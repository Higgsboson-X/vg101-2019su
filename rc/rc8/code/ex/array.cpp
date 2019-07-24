#include <iostream>
#include <cstring>
#include "array.h"

using namespace std;
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

// array;
// ================================================================== //

void Array::enlarge() {

	_size *= 2;
	int* new_arr = new int[_size];
	memcpy(new_arr, _arr, _card * sizeof(int));
	delete[] _arr;
	_arr = new_arr;

}

void Array::shrink() {

	if (_size <= 10) {
		// initial size;
		return;
	}
	_size /= 2;
	int* new_arr = new int[_size];
	memcpy(new_arr, _arr, _card * sizeof(int));
	delete[] _arr;
	_arr = new_arr;

}


Array::Array(int init_size) {

	_card = 0;
	_size = init_size;
	_arr = new int[init_size];

}

Array::~Array() {

	delete[] _arr;

}

int Array::get_size() {

	return _size;

}

int Array::get_card() {

	return _card;

}


bool Array::insert(int elt) {

	bool resized = false;
	if (_card == _size) {
		// resize;
		enlarge();
		resized = true;
	}
	_arr[_card++] = elt;

	return resized;

}


int Array::remove(int elt) {

	if (_card == 0) {
		return 0;
	}

	int tmp, i = 0, count = 0;
	while (i < _card) {
		if (_arr[i] == elt) {
			_arr[i] = _arr[--_card];
			count++;
		}
		i++;
	}
	if (2 * _card == _size) {
		// resize;
		shrink();
	}

	return count;

}


void Array::print() {

	cout << "------- print -------\n";
	cout << "cardinality = " << _card << ", size = " << _size << endl;
	for (int i = 0; i < _card; i++) {
		cout << _arr[i] << " ";
	}
	cout << endl;

}

// set;
// ================================================================== //
Set::Set(int init_size) : Array(init_size) {}

bool Set::insert(int elt) {

	if (_card == _size) {
		// resize;
		enlarge();
	}

	for (int i = 0; i < _card; i++) {
		if (_arr[i] == elt) {
			return false;
		}
	}
	_arr[_card++] = elt;

	return true;

}

int Set::remove(int elt) {

	if (_card == 0) {
		return 0;
	}

	int tmp, i = 0;
	while (i < _card) {
		if (_arr[i] == elt) {
			_arr[i] = _arr[--_card];
			if (2 * _card == _size) {
				// resize;
				shrink();
			}
			return 1;
		}
		i++;
	}

	return 0;

}

// ordered array;
// ================================================================== //
OrderedArray::OrderedArray(int init_size) : Array(init_size) {}

bool OrderedArray::insert(int elt) {

	if (_card == 0) {
		_arr[0] = elt;
		_card++;
		return false;
	}

	int pos = binary_search(_arr, 0, _card - 1, elt);
	bool resized = false;
	if (_card == _size) {
		enlarge();
		resized = true;
	}
	for (int i = _card; i > pos; i--) {
		_arr[i] = _arr[i-1];
	}
	_arr[pos] = elt;
	_card++;
	return resized;

}

int OrderedArray::remove(int elt) {

	if (_card == 0) {
		return 0;
	}

	int i = 0, j;
	while (i < _card) {
		if (_arr[i] == elt) {
			for (j = i; j < _card; j++) {
				if (_arr[j] != elt) {
					break;
				}
			}
			while (j < _card) {
				_arr[i++] = _arr[j++];
			}
			_card = i;
			if (2 * _card == _size) {
				shrink();
			}
			return j - i;
		}
		i++;
	}

	return 0;

}
