#include<iostream>
#include<climits>

using namespace std;

// time : O(n^3)
// space: O(1)

int maximumSubarraySum(int arr[], int n) {

	int maxSofar = INT_MIN;

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			// find out the sum of elements in the subarray that starts at the ith index and ends at the jth index

			int s = 0;

			for (int k = i; k <= j; k++) {
				s += arr[k];
			}

			maxSofar = max(maxSofar, s);

		}

	}

	return maxSofar;

}

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << maximumSubarraySum(arr, n) << endl;

	return 0;
}