// /***************************************************************************************
// * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
// *
// * NEMU is licensed under Mulan PSL v2.
// * You can use this software according to the terms and conditions of the Mulan PSL v2.
// * You may obtain a copy of Mulan PSL v2 at:
// *          http://license.coscl.org.cn/MulanPSL2
// *
// * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
// *
// * See the Mulan PSL v2 for more details.
// ***************************************************************************************/

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
	char expr[100];
	word_t new;
	word_t old;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;


void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }
  head = NULL;
  free_ = wp_pool;
}


static WP* new_wp() {
	assert(free_);
	WP* ret = free_;
	free_ = free_->next;
	ret->next = head;
	head = ret;
	return ret;
}


static void free_wp(WP *wp) {
	if(wp == NULL) {
		printf("wp == NULL \n");
		assert(0);
	}
	else if( wp == head && wp->next == NULL ) {
		wp->next = free_;
		free_ = wp;
		head = NULL;
		return;
	}
	else if( wp == head && wp->next != NULL ) {
		head = wp->next;
		wp->next = free_;
		free_ = wp;
		return;
	}
	else {
		WP *tmp = head;
		while( tmp->next != NULL ) {
			if( tmp->next == wp ) 
				break;
			tmp = tmp->next;
		}
		if( tmp->next == NULL ) {
			printf("free_wp: Cannot find wp. \n");
			assert(0);
		}
		tmp->next = wp->next;
		wp->next = free_;
		free_ = wp;
	}
}


void wp_set( char *expr, word_t result) {
	WP* wp = new_wp();
	strcpy(wp->expr, expr);
	wp->old = result;
	printf("Hardware watchpoint %d: %s\n", wp->NO, wp->expr);
}


void wp_display() {
	WP* tmp = head;
	if( tmp == NULL ) {
		printf("No watchpoint.\n");
		return;
	}
	printf("%-8s%8s\n", "NUM", "What");   ////
	while( tmp != NULL ) {
		printf("%-8d%8s\n", tmp->NO, tmp->expr);
		tmp = tmp->next;
	}
}


void wp_delete ( int no ) {
	assert( no < NR_WP );
	if( head == NULL ) {
		printf("No watchpoints exist.\n");
	}
	else {
		WP *tmp = head;
		while( (tmp->NO != no) && (tmp->NO < NR_WP-1) ) {
			tmp = tmp->next;
		}
		if(tmp == NULL) {
			printf("Watchpoint %d does't exist.\n", no);
		}
		else {
			free_wp(tmp);
			printf("Delete watchpoint %d: %s\n", tmp->NO, tmp->expr);
		}
	}
}


void wp_difftest() {
	WP* tmp = head;
	while( tmp != NULL ) {
		bool success;
		word_t new_value = expr(tmp->expr, &success);

		if( tmp->old != new_value ) {
			printf("Watchpoint %d: %s\n"
						 "Old value = %u\n"
						 "New value = %u\n",
						 tmp->NO, tmp->expr, tmp->old, new_value);
			tmp->old = new_value;
			nemu_state.state = NEMU_STOP;
		}
		tmp = tmp->next;
	}
} 


// /* TODO: Implement the functionality of watchpoint */


//===============================================================================================================


//  #include "sdb.h"
//  #include "watchpoint.h"

// WP *new_wp()
// {
//   if (!free_)
//     assert(0);
//   WP *last = NULL;
//   WP *now = free_;
//   while (now->next)
//   {
//     last = now;
//     now = now->next;
//   }
//   if (last)
//     last->next = NULL;
//   else
//     free_ = NULL;

//   last = head;
//   if (last)
//   {
//     while (last->next)
//     {
//       last = last->next;
//     }
//     last->next = now;
//   }
//   else
//   {
//     head = now;
//   }

//   return now;
// }


// void free_wp(WP *wp)
// {
//   WP *now = head;
//   if (head == wp)
//   {
//     head = head->next;
//     wp->next = NULL;
//     now = free_;
//     if (!free_)
//     {
//       free_ = wp;
//     }
//     else
//     {
//       while (now->next)
//       {
//         now = now->next;
//       }
//       now->next = wp;
//     }
//   }
//   else
//   {
//     while (now && now->next != wp)
//     {
//       now = now->next;
//     }
//     if (now)
//     {
//       now->next = wp->next;
//       wp->next = NULL;
//       now = free_;
//       if (!free_)
//       {
//         free_ = wp;
//       }
//       else
//       {
//         while (now->next)
//         {
//           now = now->next;
//         }
//         now->next = wp;
//       }
//     }
//   }
// }


// int set_watchpoint(char *e)
// {
//   bool flag;
//   WP *wp = new_wp();
//   wp->old_val = expr(e, &flag);
//   wp->type = 0;
//   strcpy(wp->expr, e);

//   return wp->NO;
// }


// bool delete_watchpoint(int NO)
// {
//   WP *wp = head;
//   while (wp && wp->NO != NO)
//   {
//     wp = wp->next;
//   }
//   if (wp->NO == NO)
//   {
//     free_wp(wp);
//     return true;
//   }
//   else
//   {
//     printf("NO %d watchpoint/breakpoint not found\n", NO);
//     return false;
//   }
// }


// void list_watchpoint(void)
// {
//   printf("NO  Expr            Old Value\n");
//   WP *now = head;
//   while (now)
//   {
//     if (now->type == 0)
//     {
//       printf("%2d  %-16s%#010x\n", now->NO, now->expr, now->old_val);
//       break;
//     }
//     now = now->next;
//   }
// }



// WP *scan_watchpoint(void)
// {
//   bool flag;
//   WP *now = head;
//   while (now)
//   {
//     if (now->type)
//     {
//       if (now->new_val == 1)
//       {
//         cpu.eip -= 1;
//         now->new_val = 2;
//       }
//       else if (now->new_val == 2)
//       {
//         *now->expr = *(char *)guest_to_host(now ->old_val);
//         *(char *)guest_to_host(now->old_val) = 0xcc;
//       }
//       //恢复断点.
//       now = now->next;
//       continue;
//     }
//     else if (now->old_val != expr(now->expr, &flag))
//     {
//       printf("Hit watchpoint %d at address %#010x\n", now->NO, cpu.eip);
//       printf("expr      = %s\n", now->expr);
//       printf("old value = %#x\n", now->old_val);
//       printf("new value = %#x\n", expr(now->expr, &flag));
//       printf("promgram paused\n");
//       nemu_state = NEMU_STOP;
//       now->old_val = expr(now->expr, &flag);
//       return now;
//     }
//     now = now->next;
//   }

//   return NULL;
// }


// int set_breakpoint(char *e)
// {
//   bool flag;
//   WP *wp = new_wp();
//   wp->old_val = expr(e, &flag);
//   wp->new_val = 0;
//   wp->type = 1;
//   *wp->expr = *(char *)guest_to_host(wp->old_val);
//   *(char *)guest_to_host(wp->old_val) = 0xcc;

//   return wp->NO;
// }


// void recover_int3()
// {
//   WP *now = head;
//   while (now)
//   {
//     if (now->type == 1 && now->old_val == cpu.eip)
//     {
//       *(char *)guest_to_host(now->old_val) = *now->expr;
//       now->new_val = 1;
//       break;
//     }
//     now = now->next;
//   }
// }