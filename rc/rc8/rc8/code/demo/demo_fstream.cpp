#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream f_i("input.txt");
	ofstream f_o("output.txt");
	
	string buffer;
	char str[20];
	f_i.getline(str, 20 * sizeof(char), '|');
	cout << str << endl;
	while (f_i >> buffer) {
		f_o << buffer << endl;
		cout << "Written: " << buffer << endl;
	}

	return 0;

}
