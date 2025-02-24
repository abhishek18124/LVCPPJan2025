// constraints : n <= 100

#include<iostream>
#include<climits>

using namespace std;

// time : n + n^2 ~ O(n^2)
// space: O(n)

int maximumSubarraySumUsingPrefixSum(int arr[], int n) {

	// precompute prefix sums

	int psum[101]; // based on constraints
	psum[0] = 0;

	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + arr[i - 1];
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << psum[i] << " ";
	// }

	// cout << endl;

	// find out the maximum subarray sum

	int maxSofar = INT_MIN;

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			// find out the sum of elements in the subarray that starts at the ith index and ends at the jth index

			int s = psum[j + 1] - psum[i];
			maxSofar = max(maxSofar, s);

		}

	}

	return maxSofar;

}

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << maximumSubarraySumUsingPrefixSum(arr, n) << endl;

	return 0;
}