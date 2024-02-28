/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <memory/paddr.h>

enum {
  TK_NOTYPE = 256,
	TK_EQ, TK_NEQ, TK_GT, TK_LT, TK_GE, TK_LE,
	TK_POS, TK_NEG, TK_DEREF, 
	TK_AND, TK_OR,
	TK_NUM,
	TK_REG,
	TK_VAR,

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  {" +", TK_NOTYPE},
	{"\\(", '('}, {"\\)", ')'},
  {"\\+", '+'},	{"\\-", '-'},
	{"\\*", '*'},	{"\\/", '/'},
	{"<", TK_LT}, {">", TK_GT}, {"<=", TK_LE}, {">=", TK_GE},
  {"==", TK_EQ}, {"!=", TK_NEQ},
	{"&&", TK_AND}, {"\\|\\|", TK_OR},
	{"(0[xX][0-9A-Fa-f]+|\\b[0-9]+\\b)", TK_NUM}, 
	{"\\${1,2}\\w+", TK_REG}, 
	{"[A-Za-z_]\\w*", TK_VAR}
};


#define NR_REGEX ARRLEN(rules)
#define OFTYPES(type, types)  oftypes(type, types, ARRLEN(types))

static int bound_types[] = {')', TK_NUM, TK_REG};
static int nop_types[] = {'(',')', TK_NUM, TK_REG};
static int uop_types[] = {TK_NEG, TK_POS, TK_DEREF};

static bool oftypes(int type, int types[], int size){
    for(int i = 0; i < size; i++){
        if(type == types[i]) return true;
    }
    return false;
}


static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}


typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[9999999] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;



static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;
  nr_token = 0;

	while ( e[position] != '\0' ) {

    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;
			
     //   Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
     //       i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

			if( rules[i].token_type == TK_NOTYPE ) break;

			tokens[nr_token].type = rules[i].token_type;

			switch ( rules[i].token_type ){
    		case TK_NUM:
    		case TK_REG:
    		case TK_VAR: 
    		{               
        strncpy(tokens[nr_token].str, substr_start, substr_len);
        tokens[nr_token].str[substr_len] = '\0';
        break;
    		}
    		case '+': case '-': case '*':
    		{
        	if(nr_token==0 || !OFTYPES( tokens[nr_token - 1].type, bound_types )){
            switch ( rules[i].token_type ) {
                case '+': tokens[nr_token].type = TK_POS;   break;                
                case '-': tokens[nr_token].type = TK_NEG;   break;
                case '*': tokens[nr_token].type = TK_DEREF; break;
            }
        	}
        	break;
    		}
			}
			nr_token ++;
			break;
			}
    }
    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }
  return true;
}


bool check_parentheses( int p, int q){
	if( tokens[p].type == '(' && tokens[q].type == ')' ){
		int par = 0;
		int i = p;
		for( i = p; i <= q; i ++ ){
			if( tokens[i].type == '(' ) par ++;
			else if( tokens[i].type == ')' ) par --;
			if( par == 0 ) return i == q;
		}
	}
	return false;
}


static int find_op(int p, int q){
    int ret_op = -1;
    int par = 0;
    int op_type = 100;
		int i = p;

    for( i = p; i <= q; i++ ){
        if( tokens[i].type == '(' ){
          par++;
          continue;
        }
        else if( tokens[i].type == ')' ){
					if( par == 0 ) {
						printf("over ')' \n");
						return -1;
					}
					par--;
					continue;
				}
        else if( OFTYPES( tokens[i].type, nop_types ) == true ){
            continue;
        }
        else if( par > 0 ){
            continue;
        }
        else if( par == 0 ){
            int now_type = 0;
            switch( tokens[i].type ){ 
                case TK_OR: now_type = 1;  break;
                case TK_AND: now_type = 2; break;
                case TK_EQ: case TK_NEQ: now_type = 3;  break;
                case TK_LT: case TK_GT: case TK_GE: case TK_LE: now_type = 4; break;
                case '+': case '-': now_type = 5; break;
                case '*': case '/': now_type = 6; break;
                case TK_NEG: case TK_POS: case TK_DEREF:  now_type = 7; break;
                default: assert(0);
            }
            if(now_type < op_type || ( now_type == op_type && !OFTYPES(tokens[i].type, uop_types))){
                op_type = now_type; 
                ret_op = i;
            }
        }
    }
    if( par != 0 ) {
		printf("par != 0\n");
		return -1;
	}
    return ret_op;
}


word_t isa_reg_str2val(const char *s, bool *success);


static word_t eval_num_reg( int i, bool *pass ){
	switch ( tokens[i].type ){
		case TK_NUM:
		{
			if( strncmp("0x", tokens[i].str, 2) == 0 ) return strtoul(tokens[i].str, NULL, 16);
			else return strtoul( tokens[i].str, NULL, 10 );
		}
		case TK_REG:  return isa_reg_str2val( tokens[i].str, pass );
		default: { *pass = false;  return 0; }
	}
}


static word_t calc1(int op, word_t val, bool *pass){
	switch(op) {
		case TK_NEG:   return -val;
		case TK_POS:   return val;
		case TK_DEREF: return paddr_read(val, 4); ///
		default: *pass = false;
	}
	return 0;
}


static word_t calc2(word_t val1, int op, word_t val2, bool *pass){
	switch(op) {
		case '+': return val1 + val2;
    case '-': return val1 - val2;
    case '*': return val1 * val2;
    case '/': 
		{
			if(val2 == 0){
				*pass = false;
       	return 0;
      }
      return (sword_t)val1 / (sword_t)val2;
		}
    case TK_AND: return val1 && val2;
    case TK_OR:  return val1 || val2;
    case TK_EQ:  return val1 == val2;
		case TK_NEQ: return val1 != val2;
    case TK_GT:  return val1 > val2;
    case TK_LT:  return val1 < val2;
    case TK_GE:  return val1 >= val2;
    case TK_LE:  return val1 <= val2;
    default: *pass = false; return 0;
  }
}


static word_t eval(int p, int q, bool *pass){
    *pass = true;
    if( p > q ){
        *pass = false;
        return 0;
    }
    else if( p == q ){
        return eval_num_reg( p, pass );
    }
		else if( check_parentheses(p, q) == true )  {
			return eval( p+1, q-1, pass );
		}
    else {
        int op = find_op(p, q);
        if( op < 0 ){
            *pass = false;
						printf("op < 0 \n");
            return 0;
        }

        bool pass1 = false;
				bool pass2 = false;
        word_t val1 = eval( p, op-1, &pass1 );
        word_t val2 = eval( op+1, q, &pass2 );

        if( pass2 == false ){
          *pass = false;
          return 0;
        }
        else if( pass1 == true ){
					word_t result = calc2( val1, tokens[op].type, val2, pass );
          return result;
        }
				else {
					word_t result = calc1( tokens[op].type, val2, pass );
					return result;
				}
    }
}


word_t expr(char *e, bool *pass) {
  if (!make_token(e)) {
    *pass = false;
		printf("make_token:  *pass = false\n");
    return 0;
  }
	else
		return eval( 0, nr_token-1, pass );
}


void test_expr() {
    FILE *fp = fopen("/home/zhong/ysyx-workbench/nemu/tools/gen-expr/input","r");
    if(fp == NULL){
			perror("test_expr error");
		}
    char *e = NULL; 
    word_t correct_res = 0; 
    size_t len = 0; 
    ssize_t read = 0;
    bool success = false; 

    while (true){
        if(fscanf(fp,"%u ", &correct_res) == -1) break;
        read = getline(&e, &len, fp);
        e[read-1] = '\0'; 

        word_t res = expr(e, &success);

        assert(success);
        if(res != correct_res){
            puts(e);
            printf("Expected result: %u, got result: %u\n", correct_res, res);
            assert(0); 
        } 
    }
    fclose(fp);
    if(e) free(e); 

    Log("test_expr pass");
}



