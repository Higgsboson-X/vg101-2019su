#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

// basic;
// ================================================================== //

void swap(int* a, int* b);

// utils;
// ================================================================== //

int binary_search(int* seq, int left, int right, int elt);

// sort;
// ================================================================== //

void bubble_sort(int* seq, int n);

void insertion_sort(int* seq, int n);

void selection_sort(int* seq, int n);

void merge_sort(int* seq, int n);

void quick_sort(int* seq, int n);
void quick_sort_helper(int* seq, int left, int right);
int partition(int* seq, int left, int right);

#endif