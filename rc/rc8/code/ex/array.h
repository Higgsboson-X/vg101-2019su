#ifndef __ARRAY_H__
#define __ARRAY_H__

class Array {

protected:
	int _card;
	int _size;
	int* _arr;

	void enlarge();
	void shrink();

public:
	Array(int init_size = 10);
	~Array();
	int get_size();
	int get_card();
	// return true if not modified the size;
	bool insert(int elt);
	// return the number of elements removed;
	int remove(int elt);
	void print();

};


class Set : public Array {

public:
	Set(int init_size = 10);
	// return true on inserted;
	bool insert(int elt);
	int remove(int elt);

};


class OrderedArray : public Array {

public:
	OrderedArray(int init_size = 10);
	bool insert(int elt);
	int remove(int elt);

};

// utils;
// ================================================================== //
int binary_search(int* seq, int left, int right, int elt);

#endif