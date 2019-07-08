#include "list.h"

void test_list() {

	int m = 3;
	int n = 7;

	srand(time(NULL));

	list_t* list = create_list();
	node_t* node;

	int i, j;

	printf(">>>>>>> Insert <<<<<<<\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			node = create_node(n * i + j, rand() % n);
			insert_node(list, node);
			printf("Inserted node:\n");
			print_node(node);
			print_list(list);
			getc(stdin);
		}
	}

	print_list(list);

	printf(">>>>>>> Remove <<<<<<<\n");
	node_t* del;
	node = list->head;
	for (i = 0; i < n; i++) {
		if (node->val >= 3) {
			remove_node(list, node);
			del = node;
			node = list->head;
			printf("Deleted node:\n");
			print_node(del);
			free(del);
			print_list(list);
			getc(stdin);
		}
		else {
			node = node->next;
		}
	}

	print_list(list);

	clear_list(list);

}


int main() {

	test_list();

	return 0;

}