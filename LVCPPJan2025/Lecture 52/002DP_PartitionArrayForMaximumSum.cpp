#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// time : O(k^n)
// space: O(n) due to function call stack

int f(const vector<int>& arr, int n, int k, int i) {

	// base case

	if (i == n) {
		return 0;
	}

	// recursive case

	// f(i) = find the maximum sum from partitioning arr[i...n-1]
	// such that each subarray should have a size <= k and values
	// of a subarray are replaced by the maximum value of the sub

	// decide the next

	int maxsofar = INT_MIN;
	int maxij = INT_MIN;

	for (int j = i; j < i + k  and j < n ; j++) {

		maxij = max(maxij, arr[j]);
		maxsofar = max(maxsofar, ((j - i + 1) * maxij) + f(arr, n, k, j + 1));

	}

	return maxsofar;

}

int fTopdown(const vector<int>& arr, int n, int k, int i, vector<int>& dp) {

	// lookup

	if (dp[i] != -1) {
		// you've solved f(i) previously
		return dp[i];
	}

	// base case

	if (i == n) {
		return dp[i] = 0;
	}

	// recursive case

	// f(i) = find the maximum sum from partitioning arr[i...n-1]
	// such that each subarray should have a size <= k and values
	// of a subarray are replaced by the maximum value of the sub

	// decide the next cut

	int maxsofar = INT_MIN;
	int maxij = INT_MIN;

	for (int j = i; j < i + k  and j < n ; j++) {

		maxij = max(maxij, arr[j]);
		maxsofar = max(maxsofar, ((j - i + 1) * maxij) + fTopdown(arr, n, k, j + 1, dp));

	}

	return dp[i] = maxsofar;

}

// time : O(nk)
// space: O(n) due to dp[]
// [HW] try to optimise the space to O(k) since dp[i] only depends next k cells i.e. dp[i+1], dp[i+2], ..., dp[i+k]

int fBottomUp(vector<int>& arr, int n, int k) {

	vector<int> dp(n + 1);
	dp[n] = 0; // at the nth index of dp[] we store f(n)

	for (int i = n - 1; i >= 0; i--) {

		// dp[i] = f(i)

		// f(i) = find the maximum sum from partitioning arr[i...n-1]
		// such that each subarray should have a size <= k and values
		// of a subarray are replaced by the maximum value of the sub

		// decide the next

		int maxsofar = INT_MIN;
		int maxij = INT_MIN;

		for (int j = i; j < i + k and j < n; j++) {
			maxij = max(maxij, arr[j]);
			maxsofar = max(maxsofar, (j - i + 1) * maxij + dp[j + 1]);
		}

		dp[i] = maxsofar;

	}

	return dp[0]; // at the 0th index of dp[] we store f(0)

}

int maxSumAfterPartitioning(vector<int>& arr, int k) {

	int n = arr.size();

	// return f(arr, n, k, 0);

	// vector<int> dp(n + 1, -1);

	// return fTopdown(arr, n, k, 0, dp);

	return fBottomUp(arr, n, k);
}

int main() {

	vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
	int k = 3;

	cout << maxSumAfterPartitioning(arr, k) << endl;

	return 0;
}