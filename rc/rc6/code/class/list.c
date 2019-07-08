#include "list.h"

// list;
// ==================================================================================== //

node_t* create_node(int val) {

	node_t* node = malloc(sizeof(node_t));
	node->val = val;
	node->next = node;
	node->prev = node;

	return node;

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

	node_t* head = list->head;
	node->next = head;
	node->prev = head->prev;

	head->prev->next = node;
	head->prev = node;

	list->n += 1;

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

	printf("[%d] :: [%d] :: [%d]\n", node->prev->val, node->val, node->next->val);

}

void print_list(list_t* list) {

	printf("PRINT LIST %d - HEAD {[%d] :: [%d] :: [%d]}\n", list->n, list->head->prev->val, list->head->val, list->head->next->val);

	if (list->n == 0) {
		return;
	}

	int first = 1;
	node_t* node = list->head;
	
	while (first || node != list->head) {
		if (first) {
			first = 0;
		}
		printf("[%d] :: ", node->val);
		node = node->next;
	}
	if (list->n > 1) {
		printf("[%d]\n", node->val);
	}
	else {
		printf("\n");
	}

}
