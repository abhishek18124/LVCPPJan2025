#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int& ref1 = x;
	ref1++;
	cout << x << " " << ref1 << endl;
	const int& ref2 = x;
	cout << x << " " << ref1 << " " << ref2 << endl;
	// ref2++; // error

	return 0;
}