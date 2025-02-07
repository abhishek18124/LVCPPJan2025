#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int mask = 1;

	if ((n & mask) == 1) {
		// LSB or 0th bit of n is set therefore n is odd
		cout << "odd" << endl;
	} else {
		// LSB or 0th bit of n is not set therefore n is even
		cout << "even" << endl;
	}

	if (n & mask) {
		// LSB or 0th bit of n is set therefore n is odd
		cout << "odd" << endl;
	} else {
		// LSB or 0th bit of n is not set therefore n is even
		cout << "even" << endl;
	}

	return 0;
}