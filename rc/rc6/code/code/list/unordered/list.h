#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;

	struct Node* next;
	struct Node* prev;
} node_t;

typedef struct List {
	node_t* head;
	int n;
} list_t;

node_t* create_node(int val);
list_t* create_list();

void insert_node(list_t* list, node_t* node);
void remove_node(list_t* list, node_t* node);

void clear_list(list_t* list);

void print_node(node_t* node);
void print_list(list_t* list);

#endif