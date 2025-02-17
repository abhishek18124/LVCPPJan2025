#include<iostream>

using namespace std;


int main() {

	int a = 10;
	int b = a;

	b++;

	cout << a << endl;
	cout << b << endl;

	int c = 20;
	int& d = c; // d is a reference to c i.e. d is new name for c

	d++;

	cout << c << endl;
	cout << d << endl;

	int& e = c; // e is also a reference to c i.e. e is also a new name for c

	e++;

	cout << c << endl;
	cout << d << endl;
	cout << e << endl;

	return 0;
}