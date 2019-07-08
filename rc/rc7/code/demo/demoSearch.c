#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear_search(int* arr, int target, int n) {

	int i;
	for (i = 0; i < n - 1; i++) {
		if (arr[i] == target) {
			return i;
		}
	}

	return -1;

}

// arr is sorted;
int binary_search_helper(int* arr, int target, int a, int b) {

	if (a > b) {
		return -1;
	}
	else if (a == b) {
		if (arr[a] != target) {
			return -1;
		}
		else {
			return a;
		}
	}

	int mid = (a + b) / 2;
	if (arr[mid] == target) {
		return mid;
	}
	else if (arr[mid] < target) {
		return binary_search_helper(arr, target, mid + 1, b);
	}
	else {
		return binary_search_helper(arr, target, a, mid - 1);
	}

}


int binary_search(int* arr, int target, int n) {

	return binary_search_helper(arr, target, 0, n - 1);

}


void test_search() {

	srand(time(NULL));

	int arr[10] = {1, 3, 4, 7, 8, 9, 11, 21, 22, 23};
	int target = 7;
	int ans = linear_search(arr, target, 10);
	printf("linear search: %d \n", ans);
	ans = binary_search(arr, target, 10);
	printf("binary search: %d \n", ans);

	int i;
	for (i = 0; i < 10; i++) {
		target = rand() % 23 + 1;
		printf("TARGET: %d\n", target);
		printf("linear search: %d \n", linear_search(arr, target, 10));
		printf("binary search: %d \n", binary_search(arr, target, 10));
	}

}


int main() {

	test_search();

	return 0;

}

