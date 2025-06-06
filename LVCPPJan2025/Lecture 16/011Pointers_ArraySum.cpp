#include<iostream>

using namespace std;

int computeSum(int* arr, int n) { // this works since array name decays into a pointer

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += *(arr + i);
	}

	return sum;
}

int main() {

	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(int);

	cout << computeSum(&arr[0], n) << endl;

	return 0;
}