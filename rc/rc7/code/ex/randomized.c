#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int range_random(int x, int y) {

	return x + rand() % (y - x + 1);

}


int randomized_binary_search_helper(int* arr, int target, int left, int right) {

	if (left > right) {
		return -1;
	}
	if (left == right) {
		if (arr[left] == target) {
			return left;
		}
		else {
			return -1;
		}
	}

	int mid = range_random(left, right);
	if (arr[mid] == target) {
		return mid;
	}
	else if (arr[mid] < target) {
		return randomized_binary_search_helper(arr, target, mid + 1, right);
	}
	else {
		return randomized_binary_search_helper(arr, target, left, mid - 1);
	}

}


int randomized_binary_search(int* arr, int target, int n) {

	return randomized_binary_search_helper(arr, target, 0, n - 1);

}



void test_search() {

	srand(time(NULL));

	int arr[10] = {1, 3, 4, 7, 8, 9, 11, 21, 22, 23};
	int target = 7;

	int i;
	for (i = 0; i < 10; i++) {
		target = rand() % 23 + 1;
		printf("TARGET: %d\n", target);
		printf("randomized binary search: %d \n", randomized_binary_search(arr, target, 10));
	}

}


int main() {

	test_search();

	return 0;

}
