#include<iostream>

using namespace std;

int drr[10]; // when we create an array in global scope it is init with zero

int main() {

	// when we declare an arr[] in local scope by default it
	// contains garbage value

	int arr[5];

	cout << sizeof(arr) << endl; // 20B

	char brr[10];

	cout << sizeof(brr) << endl; // 10B

	double crr[20];

	cout << sizeof(crr) << endl; // 160B

	return 0;
}