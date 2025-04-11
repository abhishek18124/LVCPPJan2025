// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int arr[], int s, int e) {

	int pivot = arr[e];

	int i = s - 1;
	int j = s;

	while (j < e) {

		if (arr[j] < pivot) {

			// put arr[j] in the left partition
			i++;
			swap(arr[i], arr[j]);
			j++;

		} else {

			// put arr[j] in the right partition
			j++;

		}

	}

	swap(arr[i + 1], arr[e]);

	return i + 1;

}

void qs(int arr[], int s, int e) {

	// base case

	// if (s == e) {
	// 	return;
	// }

	// if (s > e) {
	// 	return;
	// }

	if (s >= e) {
		return;
	}

	// recursive case

	// 1. partition the arr[s...e] around the pivot

	int pidx = partition(arr, s, e);

	// 2. recursively, qs(arr[s...pidx-1]) and qs(arr[pidx+1...e])

	qs(arr, s, pidx - 1);
	qs(arr, pidx + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	qs(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}