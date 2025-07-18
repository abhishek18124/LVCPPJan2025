/*

	https://atcoder.jp/contests/dp/tasks/dp_o

*/

#include<iostream>
#include<vector>
#define ll long long

using namespace std;

int n;
vector<vector<int>> a;
vector<vector<ll>> dp;

const int MOD = 1e9 + 7;

// time : O(n^n)
// space: O(n) due to fn call stack

ll f(int i, int bitmask) {

	// base case

	if (bitmask == (1 << n) - 1) { // i == n
		return 1;
	}

	// recursive case

	// f(i, bitmask) = find no. of ways to pair m[i...n-1] with remaining women
	// such that bitmask keeps track of decision history i.e women already paired
	// with m[0...i-1]

	// decide for the ith man

	ll cnt = 0;

	for (int j = 0; j < n; j++) {

		// check if you can pair mi with wj ?

		if (a[i][j] == 0) continue; // mi and wj are not compatible

		// mi and wj are compatible

		if ((bitmask >> j) & 1) continue; // jth bit of bitmask is set which means wj is already paired so it cannot be paired with mi

		// mi and wj can paired

		cnt = (cnt + f(i + 1, bitmask | (1 << j))) % MOD;

	}

	return cnt % MOD;

}


// time :
// space:

ll fTopdown(int i, int bitmask) {

	// lookup
	if (dp[i][bitmask] != -1) {
		// you've solve f(i, bitmask) previously
		return dp[i][bitmask];
	}

	// base case

	if (bitmask == (1 << n) - 1) { // i == n
		return dp[i][bitmask] = 1;
	}

	// recursive case

	// f(i, bitmask) = find no. of ways to pair m[i...n-1] with remaining women
	// such that bitmask keeps track of decision history i.e women already paired
	// with m[0...i-1]

	// decide for the ith man

	ll cnt = 0;

	for (int j = 0; j < n; j++) {

		// check if you can pair mi with wj ?

		if (a[i][j] == 0) continue; // mi and wj are not compatible

		// mi and wj are compatible

		if ((bitmask >> j) & 1) continue; // jth bit of bitmask is set which means wj is already paired so it cannot be paired with mi

		// mi and wj can paired

		cnt = (cnt + fTopdown(i + 1, bitmask | (1 << j))) % MOD;

	}

	return dp[i][bitmask] = cnt % MOD;

}

int main() {

	cin >> n;

	a.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	// f(0, 0) = find the no. of ways to pair m[0..n-1] with women[0...n-1]

	// cout << f(0, 0) << endl;

	dp.resize(n + 1, vector<ll>(1 << n, -1));

	cout << fTopdown(0, 0) << endl;

	return 0;
}