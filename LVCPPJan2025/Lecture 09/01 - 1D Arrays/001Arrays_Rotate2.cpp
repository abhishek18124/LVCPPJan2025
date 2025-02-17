#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	// time : O(n)
	// space: O(1)

	for (int i = n - 1; i >= 1; i--) { // n-1 steps and each step is const
		swap(arr[i], arr[i - 1]);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;

}