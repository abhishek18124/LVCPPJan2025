/*

given a non-negative number n, find the nth fibonacci no.

Example :
	Input : n = 7
	Output : 13

*/

#include<iostream>
#include<vector>

using namespace std;

int cnt1;

// time : O(2^n)
// space: O(n)

int f(int n) {

	cnt1++;

	// base case

	if (n == 0 || n == 1) {

		// f(0) : find the 0th fibonacci no.

		// f(1) : find the 1st fibonacci no.

		return n;

	}

	// recursive case

	// f(n) : find the nth fibonacci no.

	return f(n - 1) + f(n - 2);
}

int cnt2;

// time : O(n)
// space: O(n)

int fTopdown(int n, vector<int>& dp) {

	cnt2++;

	// lookup

	if (dp[n] != -1) {
		// you've already solved f(n) previously
		return dp[n];
	}

	// base case

	if (n == 0 || n == 1) {
		return dp[n] = n;
	}

	// recursive case

	return dp[n] = fTopdown(n - 1, dp) + fTopdown(n - 2, dp);

}

// time : O(n)
// space : O(n) due dp[]

int fBottomUp(int n) {

	vector<int> dp(n + 1);

	dp[0] = 0; // at the 0th index of dp[] we store f(0)
	dp[1] = 1; // at the 1st index of dp[] we store f(1)

	for (int i = 2; i <= n; i++) {

		// dp[i] = f(i) = find the ith fib. no.

		dp[i] = dp[i - 1] + dp[i - 2];

	}

	return dp[n]; // at the nth index of dp[] we store f(n)

}

// time : O(n)
// space: O(1)

int fBottomUpSpaceOptimised(int n) {

	if (n == 0 || n == 1) return n;

	// n >= 2

	int a = 0; // 0th fib. no.
	int b = 1; // 1st fib. no.

	for (int i = 1; i <= n - 1; i++) {
		int c = a + b;
		a = b;
		b = c;
	}

	return b;

}

int main() {

	int n = 10;

	cout << f(n) << endl;

	vector<int> dp(n + 1, -1);

	// dp[0] stores f(0)
	// dp[1] stores f(1)
	// ...
	// dp[n] stores f(n)

	cout << fTopdown(n, dp) << endl;

	cout << "cnt1 = " << cnt1 << endl;
	cout << "cnt2 = " << cnt2 << endl;

	cout << fBottomUp(n) << endl;

	cout << fBottomUpSpaceOptimised(n) << endl;

	return 0;
}