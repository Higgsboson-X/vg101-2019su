#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_array(int n, int v, int r) {

	srand(time(NULL));
	int* arr = malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++) {
		if (r) {
			arr[i] = rand() % 10;
		}
		else {
			arr[i] = i;
		}
	}
	if (v) {
		printf("Verbose output: an array of size %d is created with mode (random): %d\n", n, r);
	}
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);

}

int main(int argc, char* argv[]) {

	// create an array, and print out in a style specified by `verbose` argument;
	/*
	 suppose there are the following available arguments:
	 	-h | --help					print this help message
		-n n | --length=n			length of array
		-v | --verbose				verbose output
		-r | --random				randomly set elements, or by increment
	 */
	int n = 0, 
		v = 0, 
		r = 0, 
		i = 1;
	while (i < argc) {
		if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
			puts("\t-h | --help			print this help message");
			puts("\t-n n | --length=n	\tlength of array");
			puts("\t-v | --verbose		\tverbose output");
			puts("\t-r | --random		\trandomly set elements, or by increment");
			return 0;
		}
		else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
			v = 1;
		}
		else if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--random") == 0) {
			r = 1;
		}
		else {
			if (argv[i][0] == '-' && argv[i][1] == '-') {
				// long argument;
				n = atoi(argv[i] + 9);
			}
			else {
				// short argument;
				n = atoi(argv[++i]);
			}
		}
		i++;
	}

	printf("Received argument: n = %d, v = %d, r = %d\n", n, v, r);

	print_array(n, v, r);

	return 0;

}
