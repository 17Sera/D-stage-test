// #include "../include/common.h"
// #include "../include/utils.h"
// #include "../include/debug.h"
// #include "../include/macro.h"
// #include "Vysyx_23060219_top.h"

// extern word_t   expr  (char *e, bool *success);
// extern NPCState npc_state;

// #define NR_WP 32

// typedef struct watchpoint {
//   int NO;
//   struct watchpoint *next;
// 	char expr[100];
// 	word_t new_value;           // 不能定义为 new
// 	word_t old;
// } WP;

//  WP wp_pool[NR_WP] = {};
//  WP *head = NULL, *free_ = NULL;


// void init_wp_pool() {
//   int i;
//   for (i = 0; i < NR_WP; i ++) {
//     wp_pool[i].NO = i;
//     wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
//   }
//   head = NULL;
//   free_ = wp_pool;
// }


// WP* new_wp() {
// 	assert(free_);
// 	WP* ret = free_;
// 	free_ = free_->next;
// 	ret->next = head;
// 	head = ret;
// 	return ret;
// }


// void free_wp(WP *wp) {
// 	if(wp == NULL) {
// 		printf("wp == NULL \n");
// 		assert(0);
// 	}
// 	else if( wp == head && wp->next == NULL ) {
// 		wp->next = free_;
// 		free_ = wp;
// 		head = NULL;
// 		return;
// 	}
// 	else if( wp == head && wp->next != NULL ) {
// 		head = wp->next;
// 		wp->next = free_;
// 		free_ = wp;
// 		return;
// 	}
// 	else {
// 		WP *tmp = head;
// 		while( tmp->next != NULL ) {
// 			if( tmp->next == wp ) 
// 				break;
// 			tmp = tmp->next;
// 		}
// 		if( tmp->next == NULL ) {
// 			printf("free_wp: Cannot find wp. \n");
// 			assert(0);
// 		}
// 		tmp->next = wp->next;
// 		wp->next = free_;
// 		free_ = wp;
// 	}
// }


// void wp_set( char *expr, word_t result) {
// 	WP* wp = new_wp();
// 	strcpy(wp->expr, expr);
// 	wp->old = result;
// 	printf("Hardware watchpoint %d: %s\n", wp->NO, wp->expr);
// }


// void wp_display() {
// 	WP* tmp = head;
// 	if( tmp == NULL ) {
// 		printf("No watchpoint.\n");
// 		return;
// 	}
// 	printf("%-8s%8s\n", "NUM", "What");   ////
// 	while( tmp != NULL ) {
// 		printf("%-8d%8s\n", tmp->NO, tmp->expr);
// 		tmp = tmp->next;
// 	}
// }


// void wp_delete ( int no ) {
// 	assert( no < NR_WP );
// 	if( head == NULL ) {
// 		printf("No watchpoints exist.\n");
// 	}
// 	else {
// 		WP *tmp = head;
// 		while( (tmp->NO != no) && (tmp->NO < NR_WP-1) ) {
// 			tmp = tmp->next;
// 		}
// 		if(tmp == NULL) {
// 			printf("Watchpoint %d does't exist.\n", no);
// 		}
// 		else {
// 			free_wp(tmp);
// 			printf("Delete watchpoint %d: %s\n", tmp->NO, tmp->expr);
// 		}
// 	}
// }


// void wp_difftest() {
// 	WP* tmp = head;
// 	while( tmp != NULL ) {
// 		bool success;
// 		word_t new_value = expr(tmp->expr, &success);

// 		if( tmp->old != new_value ) {
// 			printf("Watchpoint %d: %s\n"
// 						 "Old value = %u\n"
// 						 "New value = %u\n",
// 						 tmp->NO, tmp->expr, tmp->old, new_value);
// 			tmp->old = new_value;
// 			npc_state.state = NPC_STOP;
// 		}
// 		tmp = tmp->next;
// 	}
// } 