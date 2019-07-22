#include <iostream>
#include <ctime>
#include "array.h"

using namespace std;

int main() {

	srand(time(NULL));

	int i;
	cout << "------- ARRAY -------\n";
	Array a1(5);
	a1.print();
	for (i = 0; i < 7; i++) {
		cout << "enlarged: " << a1.insert(rand()%7) << endl;
	}
	a1.print();
	for (i = 0; i < 3; i++) {
		cout << "removed: " << a1.remove(i) << endl;
	}
	a1.print();

	cout << "------- SET -------\n";
	Set s1(5);
	s1.print();
	for (i = 0; i < 7; i++) {
		cout << "inserted: " << s1.insert(rand()%7) << endl;
	}
	s1.print();
	for (i = 0; i < 3; i++) {
		cout << "removed: " << s1.remove(i) << endl;
	}
	s1.print();

	cout << "------- ORDERED ARRAY -------\n";
	OrderedArray a2(5);
	a2.print();
	for (i = 0; i < 7; i++) {
		cout << "enlarged: " << a2.insert(rand()%7) << endl;
	}
	a2.print();
	for (i = 0; i < 3; i++) {
		cout << "removed: " << a2.remove(i) << endl;
	}
	a2.print();

	return 0;

}