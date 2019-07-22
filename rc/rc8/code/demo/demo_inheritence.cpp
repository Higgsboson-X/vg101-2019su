#include <iostream>

using namespace std;

class A {

	private:
		int _a;
	public:
		A() {
			cout << "constructor A1\n";
			_a = 0;
		}
		A(int a) {
			cout << "constructor a = " << a << endl;
			_a = a;
		}
		~A() {
			cout << "destructor A\n";
		}
		// `virtual` key word;
		void show() {
			cout << "a = " << _a << endl;
		}

};

class B : public A {

	private:
		int _b;
	public:
		B(int b = 1) {
			cout << "constructor b = " << b << endl;
			_b = b;
		}
		// this is how you call parent constructor function;
		B(int a, int b) : A(a) {
			cout << "constructor a = " << a << ", b = " << b << endl;
			_b = b;
		}
		~B() {
			cout << "destructor B\n";
		}
		void show() {
			// call parent function;
			A::show();
			cout << "b = " << _b << endl;
		}
		void modify(int b) {
			cout << "modified b = " << b << endl;
			_b = b;
		}

};


class Greet {

	public:
		Greet() {
			cout << "constructor greet\n";
		}
		~Greet() {
			cout << "destructor greet\n";
		}
		void greet() {
			cout << "hello, world\n";
		}

};


class D : public Greet, public A {

	private:
		string _msg;
	public:
		D() {
			cout << "constructor D\n";
			_msg = "default";
		}
		D(string msg) {
			cout << "constructor msg = " << msg << endl;
			_msg = msg;
		}
		~D() {
			cout << "destructor D\n";
		}
		void greet() {
			cout << "greet with " << _msg << endl;
		}

};


void test_A() {

	cout << "------- A -------\n";
	A a1;
	A a2(3);
	a1.show();
	a2.show();

}

void test_B() {

	cout << "------- B -------\n";
	B b1;
	B b2(1, 2);
	B b3(7);
	b1.show();
	b2.show();
	b3.show();
	b3.modify(5);
	b3.show();

}

void test_D() {

	cout << "------- D -------\n";
	D d1;
	D d2("good morning");
	d1.greet();
	d2.greet();

}

int main() {

	test_A();
	test_B();
	test_D();

	cout << "------- main -------\n";
	A* a;
	B b;
	a = &b;
	// `virtual` key word behavior;
	a->show();

	return 0;

}

