#include<iostream>
#include<string>

using namespace std;

int main() {

	string a = "hello";
	cout << a << endl;

	string b = a; // we are creating a string 'b' as a copy of string 'a'
	// here, we are using copy constructor to create a copy
	// string b(a); // here also copy const is used to create b as a copy of string 'a'
	cout << b << endl;
	b[0] = 'a';
	cout << b << endl; // string 'b' is modified to aello
	cout << a << endl; // string 'a' is still hello

	// in C++, string objects are mutable i.e. string objects can be modified

	string c;
	c = a; // here, we are assigning value of string 'a' to string 'c'
	// here, we are using copy assignment operator to create a copy
	cout << c << endl;

	return 0;
}