#include<iostream>

using namespace std;

void inc(int& ref) { // passing by reference
	ref++; // changes done to param will affect the argument
}

int main() {

	int a = 10;

	cout << a << endl;

	inc(a);

	cout << a << endl;

	return 0;

}