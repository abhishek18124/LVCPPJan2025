/*

	https://www.codechef.com/problems/TSHIRTS

*/

#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

const int MOD = 1e9 + 7;

int f(int i, int bitmask, const vector<vector<int>>& inp, int n) {

	// base case

	if (i == 101) {

		if (bitmask == (1 << n) - 1) {
			return 1; // every friend is assigned a t-shirt
		}

		return 0; // not every friend is assigned a t-shirt

	}

	// recursive case

	// f(i, bitmask) = find no. of arrangements for ids[i...100]
	// such that bitmask contains decision history i.e. friends
	// who are already assigned some t-shirt

	// decide for t-shirt id i

	// option 1 : use t-shirt id i

	int cnt = 0;

	for (int j : inp[i]) {

		// can you assign t-shirt i to friend j

		if ((bitmask >> j) & 1) continue; // friend j is already assigned a t-shirt so they cannot be assigned t-shirt i

		// assign t-shirt i to friend

		cnt = (cnt + f(i + 1, bitmask | (1 << j), inp, n)) % MOD;

	}

	// option 2 : don't use t-shirt id i

	cnt = (cnt + f(i + 1, bitmask, inp, n)) % MOD;

	return cnt % MOD;

}

int fTopdown(int i, int bitmask, const vector<vector<int>>& inp, int n, vector<vector<int>>& dp) {

	// base case

	if (i == 101) {

		if (bitmask == (1 << n) - 1) {
			return 1; // every friend is assigned a t-shirt
		}

		return 0; // not every friend is assigned a t-shirt

	}

	// lookup

	if (dp[i][bitmask] != -1) {
		return dp[i][bitmask];
	}

	// recursive case

	// f(i, bitmask) = find no. of arrangements for ids[i...100]
	// such that bitmask contains decision history i.e. friends
	// who are already assigned some t-shirt

	// decide for t-shirt id i

	// option 1 : use t-shirt id i

	int cnt = 0;

	for (int j : inp[i]) {

		// can you assign t-shirt i to friend j

		if ((bitmask >> j) & 1) continue; // friend j is already assigned a t-shirt so they cannot be assigned t-shirt i

		// assign t-shirt i to friend

		cnt = (cnt + fTopdown(i + 1, bitmask | (1 << j), inp, n, dp)) % MOD;

	}

	// option 2 : don't use t-shirt id i

	cnt = (cnt + fTopdown(i + 1, bitmask, inp, n, dp)) % MOD;

	return dp[i][bitmask] = cnt % MOD;

}

int main() {

	int t;
	cin >> t; // no. of testcases

	while (t--) {

		int n;
		cin >> n; // no. of friends

		cin.ignore();

		vector<vector<int>> inp(101); // 0th is not used

		// for each friend read t-shirt they have

		for (int i = 0; i < n; i++) {

			// read info. for the ith friend

			string s;
			getline(cin, s); // cin is an object of istream that helps in reading from the standard input stream

			istringstream iss(s);

			int num;

			while (iss >> num) {
				inp[num].push_back(i);
			}

		}

		// for (int i = 1; i <= 100; i++) {
		// 	cout << i << " : ";
		// 	for (int f : inp[i]) cout << f << " ";
		// 	cout << endl;
		// }

		// cout << f(1, 0, inp, n) << endl;

		vector<vector<int>> dp(101, vector<int>(1 << n, -1));

		cout << fTopdown(1, 0, inp, n, dp) << endl;


	}

	return 0;
}