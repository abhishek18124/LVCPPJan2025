/*

https://cses.fi/problemset/task/1158

input
5 4
8 4 1 5 3
1 2 3 2 2

ouput
13

*/

#include<iostream>
#include<vector>

using namespace std;

int f(int N, vector<int>& price, vector<int>& wgt, int i, int w) {

	// base case

	if (i == N) { // mandatory
		return 0;
	}

	if (w == 0) { // optional
		return 0;
	}

	// recursive case

	// f(i, w) = find the max. profit from items[i...n-1] s.t. current knapsack capacity is w

	// decide for the ith item

	if (wgt[i] > w) {
		// exclude the ith item from the knapsack
		return f(N, price, wgt, i + 1, w);
	}

	// option 1 : include the ith item in the knapsack

	// option 2 : exclude the ith item from the knapsack

	return max(price[i] + f(N, price, wgt, i + 1, w - wgt[i]),
	           f(N, price, wgt, i + 1, w));

}

// time : (N+1).(W+1) ~ O(NW)
// space: N due to fn call stack + (N+1).(W+1) due to dp[][] ~ O(NW)

int fTopDown(int N, vector<int>& price, vector<int>& wgt, int i, int w,
             vector<vector<int>>& dp) {

	// lookup

	if (dp[i][w] != -1) {
		// you've solve f(i, w) previously
		return dp[i][w];
	}

	// base case

	if (i == N) { // mandatory
		return dp[i][w] = 0;
	}

	if (w == 0) { // optional
		return dp[i][w] = 0;
	}

	// recursive case

	// f(i, w) = find the max. profit from items[i...n-1] s.t. current knapsack capacity is w

	// decide for the ith item

	if (wgt[i] > w) {
		// exclude the ith item from the knapsack
		return dp[i][w] = fTopDown(N, price, wgt, i + 1, w, dp);
	}

	// option 1 : include the ith item in the knapsack

	// option 2 : exclude the ith item from the knapsack

	return dp[i][w] = max(price[i] + fTopDown(N, price, wgt, i + 1, w - wgt[i], dp),
	                      fTopDown(N, price, wgt, i + 1, w, dp));

}

// time : O(NW)
// space: O(NW) due to dp[][]

int fBottomUp(int N, vector<int>& price, vector<int>& wgt, int W) {

	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0)); // 0 init handles the base case

	for (int i = N - 1; i >= 0; i--) {
		for (int w = W; w >= 1; w--) {
			// dp[i][w] = f(i, w) = find the max. profit from items[i...n-1] s.t. current capacity of the knapsack is w

			// decide for the ith item

			if (wgt[i] > w) {
				// exclude the ith item from the knapsack
				dp[i][w] = dp[i + 1][w];
			} else {
				// option 1 : include the ith item in the knapsack

				// option 2 : exclude the ith item from the knapsack

				dp[i][w] = max(price[i] + dp[i + 1][w - wgt[i]],
				               dp[i + 1][w]);
			}
		}
	}

	return dp[0][W]; // at the (0, W)th index of dp[][] we store f(0, W)

}

// time : O(NW)
// space: O(W) due to dp[]

int fBottomUpSpaceOptimised(int N, vector<int>& price, vector<int>& wgt, int W) {

	vector<int> dp(W + 1, 0); // 0 init handles the base case // dp[] init represents the Nth row

	for (int i = N - 1; i >= 0; i--) {
		for (int w = W; w >= 1; w--) {
			// dp[i][w] = f(i, w) = find the max. profit from items[i...n-1] s.t. current capacity of the knapsack is w

			// currently dp[w] is storing value of dp[i+1][w]
			// currently dp[w-wgt[i]] is storing value of dp[i+1][w-wgt[i]]

			// decide for the ith item

			if (wgt[i] > w) {
				// exclude the ith item from the knapsack
				dp[w] = dp[w];
			} else {
				// option 1 : include the ith item in the knapsack

				// option 2 : exclude the ith item from the knapsack

				dp[w] = max(price[i] + dp[w - wgt[i]],
				            dp[w]);
			}

			// now dp[w] is storing the value of dp[i][w]
		}
	}

	// at this point dp[] is storing values of the 0th row

	return dp[W]; // at the (0, W)th index of dp[][] we store f(0, W)

}

int main() {

	int N, W;
	cin >> N >> W;

	vector<int> price(N);
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}

	vector<int> wgt(N);
	for (int i = 0; i < N; i++) {
		cin >> wgt[i];
	}

	cout << f(N, price, wgt, 0, W) << endl;

	vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));

	cout << fTopDown(N, price, wgt, 0, W, dp) << endl;

	cout << fBottomUp(N, price, wgt, W) << endl;

	cout << fBottomUpSpaceOptimised(N, price, wgt, W) << endl;

	return 0;
}