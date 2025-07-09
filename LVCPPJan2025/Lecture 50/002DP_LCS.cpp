/*

Given two strings s1 and s2, return the length of their longest common subsequence.

If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example :

	Input : s1 = "ATGC", s2 = "AGCT"
	Output: 3
	Explanation : "AGC" is the LCS between s1 and s2

	Input : s1 = "AGGTAB", s2 = "GXTXAYB"
	Output: 4
	Explanation : “GTAB” is the LCS between s1 and s2

*/

#include<iostream>
#include<vector>

using namespace std;

// time : O(2^(M+N))
// space: O(M+N)

int f(string& s1, string& s2, int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) {

		// f(m, j) = find the length of the lcs b/w s1[m...m-1] i.e. "" and s2[j...n-1]

		// f(i, n) = find the length of the lcs b/w s1[i...m-1] and s2[n...n-1] i.e. ""

		return 0;
	}

	// recursive case

	// f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]

	if (s1[i] == s2[j]) {

		// ask your friend to find the length of the lcs b/w s1[i+1...m-1]
		// and s2[j+1...n-1]

		return 1 + f(s1, s2, m, n, i + 1, j + 1);

	}

	// s1[i] != s2[j]

	return max(f(s1, s2, m, n, i + 1, j),
	           f(s1, s2, m, n, i, j + 1));


}

// time : O(MN)
// space: (M+N) due to fn call stack + (MN) due to dp[][] ~ O(MN)

int fTopDown(string& s1, string& s2, int m, int n, int i, int j,
             vector<vector<int>>& dp) {

	// lookup

	if (dp[i][j] != -1) {
		// you've solve f(i, j) previously
		return dp[i][j];
	}

	// base case

	if (i == m || j == n) {

		// f(m, j) = find the length of the lcs b/w s1[m...m-1] i.e. "" and s2[j...n-1]

		// f(i, n) = find the length of the lcs b/w s1[i...m-1] and s2[n...n-1] i.e. ""

		return dp[i][j] = 0;
	}

	// recursive case

	// f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]

	if (s1[i] == s2[j]) {

		// ask your friend to find the length of the lcs b/w s1[i+1...m-1]
		// and s2[j+1...n-1]

		return dp[i][j] = 1 + fTopDown(s1, s2, m, n, i + 1, j + 1, dp);

	}

	// s1[i] != s2[j]

	return dp[i][j] = max(fTopDown(s1, s2, m, n, i + 1, j, dp),
	                      fTopDown(s1, s2, m, n, i, j + 1, dp));


}

// time : O(mn)
// space: O(mn) due to dp[][]

int fBottomUp(string& s1, string& s2, int m, int n) {

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 0-init handles base case

	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			// dp[i][j] =  f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]
			if (s1[i] == s2[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
			} else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	// for (int i = 0; i <= m; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	string answer = "";

	int i = 0;
	int j = 0;

	while (!(i == m || j == n)) {
		if (s1[i] == s2[j]) {
			answer += s1[i]; // s2[j]
			i++;
			j++;
		} else if (dp[i][j] == dp[i][j + 1]) {
			j++;
		} else {
			i++;
		}
	}

	cout << answer << endl;

	return dp[0][0]; // at the 0,0th index of dp[][] we store f(0, 0)

}

// time : O(mn)
// space: 2n ~ O(n) due to curr[] and next[]

int fBottomUpSpaceOptimised(string& s1, string& s2, int m, int n) {

	vector<int> next(n + 1, 0); // current next[] represents the mth row of dp[][]

	for (int i = m - 1; i >= 0; i--) {
		vector<int> curr(n + 1, 0);
		for (int j = n - 1; j >= 0; j--) {
			if (s1[i] == s2[j]) {
				curr[j] = 1 + next[j + 1]; // curr[j] is like dp[i][j] and next[j+1] is like dp[i+1][j+1]
			} else {
				curr[j] = max(curr[j + 1], next[j]);

				// curr[j] is like dp[i][j]
				// curr[j+1] is like dp[i][j+1]
				// next[j] is like dp[i+1][j]

			}
		}
		next = curr;
	}

	// at this point next[] containts the 0th row of dp[][]

	return next[0]; // next[0] is like dp[0][0]

}

// time : O(mn)
// space: O(n) due to dp[]

int fBottomUpSpaceOptimised2(string& s1, string& s2, int m, int n) {

	vector<int> dp(n + 1, 0); // at this point dp[] represents the mth row of the dp-matrix

	for (int i = m - 1; i >= 0; i--) {

		int dp_iplus1_jplus1 = 0;

		for (int j = n - 1; j >= 0; j--) {

			// at present dp[j] represents dp[i+1][j]

			int dp_iplus1_j = dp[j]; // this will be the diagonal cell in the next iteration

			if (s1[i] == s2[j]) {
				dp[j] = 1 + dp_iplus1_jplus1;
			} else {
				// at present
				// dp[j+1] represents dp[i][j+1]
				// d[j] represents dp[i+1][j]
				dp[j] = max(dp[j + 1], dp[j]);
			}

			dp_iplus1_jplus1 = dp_iplus1_j;
		}

	}

	// at this point dp[] represents the 0th row of the dp-matrix

	return dp[0];  // dp[0] is like dp-matrix[0][0]

}

int main() {

	string s1("ATGC");
	string s2("AGCT");

	int m = s1.size();
	int n = s2.size();

	cout << f(s1, s2, m, n, 0, 0) << endl;

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

	cout << fTopDown(s1, s2, m, n, 0, 0, dp) << endl;

	cout << fBottomUp(s1, s2, m, n) << endl;

	cout << fBottomUpSpaceOptimised(s1, s2, m, n) << endl;

	cout << fBottomUpSpaceOptimised2(s1, s2, m, n) << endl;

	return 0;
}