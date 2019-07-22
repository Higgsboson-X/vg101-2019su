#include <iostream>
#include <cstring>

using namespace std;

bool operator>(string a, string b) {

	return a.length() > b.length();

}

int main() {

	string a, b;
	cin >> a >> b;
	cout << (a > b) << endl;

	return 0;

}
