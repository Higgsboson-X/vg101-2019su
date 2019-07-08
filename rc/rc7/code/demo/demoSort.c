#include <time.h>
#include "sort.h"
#define MAX_INT_ELT 30

void print_list(int* seq, int n) {

	for (int i = 0; i < n; i++) {
		printf("%d ", seq[i]);
	}
	printf("\n");

}


void test_sort(int* seq, int n, void (*sort_alg)(int*, int)) {

	int* copy = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		copy[i] = seq[i];
	}

	sort_alg(copy, n);
	print_list(copy, n);

	free(copy);

}


int main() {

	srand(time(NULL));

	int n = 20;
	int* seq = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		seq[i] = rand() % MAX_INT_ELT;
	}

	puts("List:");
	print_list(seq, n);
	puts("Bubble sort:");
	test_sort(seq, n, bubble_sort);
	puts("Insertion sort:");
	test_sort(seq, n, insertion_sort);
	puts("Quick sort:");
	test_sort(seq, n, quick_sort);

	free(seq);

}