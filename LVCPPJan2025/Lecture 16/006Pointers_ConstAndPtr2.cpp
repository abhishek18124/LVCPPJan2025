#include<iostream>

using namespace std;

int main() {

	int x = 10;

	int* ptr1 = &x; // ptr to int
	cout << *ptr1 << " " << x << endl;
	(*ptr1)++;
	cout << *ptr1 << " " << x << endl;

	const int* ptr2 = &x; // ptr to const-int
	cout << *ptr1 << " " << x << " " << *ptr2 << endl;
	// (*ptr2)++; // error

	int* const ptr3 = &x; // const ptr to int
	(*ptr3)++;
	cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << endl;

	int y = 20;
	ptr1 = &y;
	cout << *ptr1 << endl;
	ptr2 = &y;
	cout << *ptr2 << endl;
	// ptr3 = &y; // error

	const int* const ptr4 = &x; // const ptr to const-int
	cout << *ptr4 << endl;
	// (*ptr4)++; // error same as ptr2
	// ptr4 = &y; // error same as ptr3


	return 0;
}