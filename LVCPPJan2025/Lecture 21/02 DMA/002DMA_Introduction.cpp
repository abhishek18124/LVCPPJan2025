#include<iostream>

using namespace std;

int main() {

	int* ptr = new int;
	*ptr = 20;
	cout << *ptr << endl;
	// cout << ptr << endl;

	delete ptr; // to release the memory to which ptr was pointing to initially

	ptr = new int;
	*ptr = 40;
	cout << *ptr << endl;

	char* chptr = new char;
	*chptr = 'A';
	cout << *chptr << endl;

	double* dptr = new double;
	*dptr = 3.14;
	cout << *dptr << endl;

	return 0;
}