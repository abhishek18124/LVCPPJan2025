/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year
you can sell the first or the last wine in the row. However, the price of wines increases
over time.

Let the initial prices of the wines be [p_1, p_2, ... , p_n]. In the yth year, the profit
from the kth wine will be y*p_k.

Find the maximum profit from all the wines.

Example :
	Input : prices[] = {2, 3, 5, 1, 4}
	Ouptut: 50

*/

#include<iostream>
#include<vector>

#define vvvi vector<vector<vector<int>>>
#define vvi vector<vector<int>>

using namespace std;

int f(vector<int> p, int i, int j, int y) {

	// base case

	if (i == j) {
		return y * p[i]; // y * p[j]
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell the ith bottle of wine in the yth year

	// option 2 : sell the jth bottle of wine in the yth year

	return max(y * p[i] + f(p, i + 1, j, y + 1) ,
	           y * p[j] + f(p, i, j - 1, y + 1));

}

// time : O(n^3)
// space: O(n^3) due to dp[][][]

int fTopDown(vector<int> p, int i, int j, int y, vvvi& dp) {

	// lookup
	if (dp[i][j][y] != -1) {
		// you've solved f(i, j, y) previously
		return dp[i][j][y];
	}

	// base case

	if (i == j) {
		return dp[i][j][y] = y * p[i]; // y * p[j]
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell the ith bottle of wine in the yth year

	// option 2 : sell the jth bottle of wine in the yth year

	return dp[i][j][y] = max(y * p[i] + fTopDown(p, i + 1, j, y + 1, dp) ,
	                         y * p[j] + fTopDown(p, i, j - 1, y + 1, dp));

}

// time : O(n^2)
// space: O(n^2) due to dp[][]

int fTopDownStateOptimised(vector<int> p, int i, int j, vvi& dp) {

	int n = p.size();
	int y = n - j + i;

	// lookup
	if (dp[i][j] != -1) {
		// you've solved f(i, j, y) previously
		return dp[i][j];
	}

	// base case

	if (i == j) {
		return dp[i][j] = y * p[i]; // y * p[j]
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell the ith bottle of wine in the yth year

	// option 2 : sell the jth bottle of wine in the yth year

	return dp[i][j] = max(y * p[i] + fTopDownStateOptimised(p, i + 1, j, dp) ,
	                      y * p[j] + fTopDownStateOptimised(p, i, j - 1, dp));

}

// time : O(n^2)
// space: O(n^2)
// [HW] optimise the space to O(n)

int fBottomUp(const vector<int>& p, int n) {

	vvi dp(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		// int j = i;
		// int y = n;
		// dp[i][j] = p[i] * y;
		dp[i][i] = p[i] * n;
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			// dp[i][j] = f(i, j)
			int y = n - j + i;
			dp[i][j] = max(y * p[i] + dp[i + 1][j],
			               y * p[j] + dp[i][j - 1]);
		}
	}

	return dp[0][n - 1]; // at the 0,n-1th index of dp[][] we store f(0, n-1)

}

int main() {

	vector<int> p = {2, 3, 5, 1, 4};
	int n = p.size();

	cout << f(p, 0, n - 1, 1) << endl;

	vvvi dp1(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));

	cout << fTopDown(p, 0, n - 1, 1, dp1) << endl;

	vvi dp2(n, vector<int>(n, -1));

	cout << fTopDownStateOptimised(p, 0, n - 1, dp2) << endl;

	cout << fBottomUp(p, n) << endl;

	return 0;
}