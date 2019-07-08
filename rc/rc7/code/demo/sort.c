#include "sort.h"

// basic;
// ================================================================== //

void swap(int* a, int* b) {

	int tmp = *a;
	*a = *b;
	*b = tmp;

}

// utils;
// ================================================================== //

int binary_search(int* seq, int left, int right, int elt) {

	// search the position to insert the element;
	if (left == right) {
		return seq[right] <= elt ? right + 1 : right;
	}
	else if (left == right - 1) {
		if (seq[right] <= elt) {
			return right + 1;
		}
		else if (seq[left] <= elt) {
			return left + 1;
		}
		else {
			return left;
		}
	}

	int mid = (left + right) / 2;

	if (seq[mid] <= elt) {
		return binary_search(seq, mid, right, elt);
	}
	else {
		return binary_search(seq, left, mid, elt);
	}

}

// sort;
// ================================================================== //

void bubble_sort(int* seq, int n) {

	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (seq[j] > seq[j + 1]) {
				swap(seq + j, seq + j + 1);
			}
		}
	}

}


void insertion_sort(int* seq, int n) {

	int i, j, ind, tmp;
	for (i = 1; i < n; i++) {
		tmp = seq[i];
		ind = binary_search(seq, 0, i - 1, tmp);
		if (ind != i) {
			if (ind == i - 1) {
				swap(seq + i, seq + i - 1);
			}
			else {
				for (j = i - 1; j >= ind; j--) {
					seq[j + 1] = seq[j];
				}
				seq[ind] = tmp;
			}
		}
	}

}

// not implemented;

void selection_sort(int* seq, int n) {}


void merge_sort(int* seq, int n) {}


void quick_sort(int* seq, int n) {

	quick_sort_helper(seq, 0, n - 1);

}

void quick_sort_helper(int* seq, int left, int right) {

	if (left >= right) {
		return;
	}

	int p_ind;
	p_ind = partition(seq, left, right);
	
	quick_sort_helper(seq, left, p_ind - 1);
	quick_sort_helper(seq, p_ind + 1, right);

}

int partition(int* seq, int left, int right) {

	int n = right - left + 1;
	if (n == 2) {
		if (seq[left] > seq[right]) {
			swap(seq + left, seq + right);
		}
		return right;
	}

	int pivot = rand() % n + left;

	swap(seq + left, seq + pivot);
	int i = left + 1,
		j = right;
	
	while (i < j) {
		while (i <= right && seq[i] < seq[left]) {
			i++;
		}
		while (j > left && seq[j] >= seq[left]) {
			j--;
		}
		if (i < j) {
			swap(seq + i, seq + j);
		}
	}

	swap(seq + left, seq + j);

	return j;

}


