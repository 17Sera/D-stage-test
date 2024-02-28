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


/* TODO: Implement the functionality of watchpoint */
