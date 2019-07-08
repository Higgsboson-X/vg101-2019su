#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Node {
	int id;
	int val;

	struct Node* next;
	struct Node* prev;
} node_t;

typedef struct List {
	node_t* head;
	int n;
} list_t;

int node_less(node_t* n1, node_t* n2);

node_t* create_node(int id, int val);
list_t* create_list();

void insert_node(list_t* list, node_t* node);
void remove_node(list_t* list, node_t* node);

void clear_list(list_t* list);

void print_node(node_t* node);
void print_list(list_t* list);

#endif