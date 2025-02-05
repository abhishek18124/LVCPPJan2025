#include<iostream>

using namespace std;

int main() {

	const int y = 20;
	cout << y << endl;
	// y++; // error since y is read-only

	// const int z; // error since const var. must be init.
	// z = 20;

	return 0;
}