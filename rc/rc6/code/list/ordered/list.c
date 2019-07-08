#include "list.h"

// utils;
// ==================================================================================== //

int node_less(node_t* n1, node_t* n2) {

	if (n1->id != n2->id) {
		return (n1->id < n2->id);
	}
	else {
		return (n1->val < n2->val);
	}

}

// list;
// ==================================================================================== //

node_t* create_node(int id, int val) {

	node_t* node = malloc(sizeof(node_t));
	node->id = id;
	node->val = val;
	node->next = node;
	node->prev = node;

}

list_t* create_list() {

	list_t* list = malloc(sizeof(list_t));
	list->head = NULL;
	list->n = 0;

	return list;

}

void insert_node(list_t* list, node_t* node) {

	if (list->n == 0) {
		list->head = node;
		list->n = 1;
		return;
	}
	
	node_t* iter = list->head;
	int first  = 1;
	while (first || iter != list->head) {
		if (first) {
			first = 0;
		}
		if (!node_less(node, iter) && !node_less(iter->next, node)) {
			node->prev = iter;
			node->next = iter->next;
			
			iter->next->prev = node;
			iter->next = node;
			list->n += 1;
			return;
		}
		iter = iter->next;
	}
	// largest in the list, or previously single node;
	node->prev = list->head->prev;
	node->next = list->head;
	list->head->prev->next = node;
	list->head->prev = node;
	list->n += 1;
	// previously single node;
	if (node_less(node, list->head)) {
		list->head = node;
	}

}

void remove_node(list_t* list, node_t* node) {

	if (list->n == 0) {
		perror("Empty list");
		return;
	}
	if (list->n == 1) {
		if (node != list->head) {
			perror("Node does not exist");
			return;
		}
		list->head = NULL;
		list->n = 0;
		return;
	}

	node->prev->next = node->next;
	node->next->prev = node->prev;

	if (list->head == node) {
		list->head = node->next;
	}

	node->next = node;
	node->prev = node;

	list->n -= 1;

}

void clear_list(list_t* list) {

	if (list->n == 0) {
		free(list);
		return;
	}

	node_t* node = list->head;

	while (list->n > 0) {
		remove_node(list, node);
		free(node);
		node = list->head;
	}

	free(list);

}


// print;
// ==================================================================================== //

void print_node(node_t* node) {

	if (node == NULL) {
		perror("Null");
		return;
	}

	printf("[id-%d, val-%d] :: [id-%d, val-%d] :: [id-%d, val-%d]\n", node->prev->id, node->prev->val, node->id, node->val, node->next->id, node->next->val);

}

void print_list(list_t* list) {

	printf("PRINT LIST %d - HEAD {%d :: [id-%d, val-%d] :: %d}\n", list->n, list->head->prev->id, list->head->id, list->head->val, list->head->next->id);

	if (list->n == 0) {
		return;
	}

	int first = 1;
	node_t* node = list->head;
	
	while (first || node != list->head) {
		if (first) {
			first = 0;
		}
		printf("[id-%d, val-%d] :: ", node->id, node->val);
		node = node->next;
	}
	if (list->n > 1) {
		printf("[id-%d, val-%d]\n", node->id, node->val);
	}
	else {
		printf("\n");
	}

}