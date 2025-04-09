// constraints : n <= 100

#include<iostream>

using namespace std;

void merge(int arr[], int s, int m, int e) {

	// arr[s...m] is sorted and arr[m+1...e] is sorted
	// you've to merge the two sorted subarrays such
	// that arr[s...e] becomes sorted

	int i = s;
	int j = m + 1;
	int k = s;

	int C[100]; // based on constraints

	while (i <= m and j <= e) {

		if (arr[i] <= arr[j]) {
			C[k] = arr[i];
			i++;
			k++;
		} else {
			C[k] = arr[j];
			j++;
			k++;
		}

	}

	while (i <= m) {
		C[k] = arr[i];
		i++;
		k++;
	}

	while (j <= e) {
		C[k] = arr[j];
		j++;
		k++;
	}

	for (int l = s; l <= e; l++) { // copy sorted values in C[s...e] to arr[s...e]
		arr[l] = C[l];
	}

}

void mergeSort(int arr[], int s, int e) {

	// base case

	if (s == e) {
		// mergeSort(arr[s...s])
		return;
	}

	// recursive case

	// f(s, e) : merge sort arr[s...e]

	// 1. divide the arr[s...e] around the midPoint

	int m = s + (e - s) / 2;

	// 2. ask your friend to mergeSort(arr[s...m]) and ask your friend to mergeSort(arr[m+1..e])

	mergeSort(arr, s, m);
	mergeSort(arr, m + 1, e);

	// 3. merge the two sorted subarrays arr[s...m] and arr[m+1...e]

	merge(arr, s, m, e);

}

int main() {

	int arr[] = {50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}