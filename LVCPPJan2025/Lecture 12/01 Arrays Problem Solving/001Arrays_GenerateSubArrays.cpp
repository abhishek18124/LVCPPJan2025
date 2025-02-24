#include<iostream>

using namespace std;

// time : O(n^3) since to generate a subarray we spend linear time in the worst-case

void generateSubarrays(int arr[], int n) {

	// iterate over all the possible starting indices of subarrays

	for (int i = 0; i <= n - 1; i++) {

		// for given starting index i, iterate over all the possible ending indices of subarrays

		for (int j = i; j <= n - 1; j++) {

			// generate the subarray that starts at the ith index and ends at the jth index

			for (int k = i; k <= j; k++) {
				cout << arr[k] << " ";
			}

			cout << endl;

		}

		cout << endl;

	}

}

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	generateSubarrays(arr, n);

	return 0;

}