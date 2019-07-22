#include <iostream>

// definition should be in .h file in most of the cases;

using namespace std;

// .h file;
class A {

	private:
		int _a;
	public:
		A();
		A(int a);
		~A();
		void show();

};

// .c file;
A::A() {

	cout << "constructor A1\n";
	_a = 0;

}

A::A(int a) {

	cout << "constructor A2\n";
	_a = a;

}

A::~A() {

	cout << "destructor A\n";

}

void A::show() {

	cout << "access private data: " << _a << endl;

}


void sub_call() {

	A a3(3);
	a3.show();

}

// main.c
int main() {

	A a1;
	A a2(7);

	sub_call();

	a1.show();
	a2.show();

	return 0;

}
