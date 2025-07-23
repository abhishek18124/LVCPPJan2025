/*

given an integer inp as a string, design a recursive algorithm to find count
of all the non-negative numbers up to inp whose sum of digits is equal to K.


constraints :
	inp <= 1e18
	k <= 200

*/

#include<iostream>
#include<cstring>

using namespace std;

string inp;
int n;
int k;

int dp[20][2][200];

int f(int i, bool isPrefixSame, int digitSum) {

	// lookup

	if (dp[i][isPrefixSame][digitSum] != -1) {
		return dp[i][isPrefixSame][digitSum];
	}

	// base case

	if (i == n) {

		if (digitSum == k) { // you've built a an out which is valid i.e. it has a digitSum of k
			return dp[i][isPrefixSame][digitSum] = 1;
		} else { // you've built a an out which is not valid i.e. digitSum is not equal to k
			return dp[i][isPrefixSame][digitSum] = 0;
		}

	}

	// recursive case

	int upperBound = isPrefixSame ? inp[i] - '0' : 9;

	int cnt = 0;

	for (int d = 0; d <= upperBound; d++) {

		cnt += f(i + 1, isPrefixSame and d == upperBound, digitSum + d);

	}

	return dp[i][isPrefixSame][digitSum] = cnt;

}


int main() {

	memset(dp, -1, sizeof(dp));

	cin >> inp >> k;

	n = inp.size();

	cout << f(0, true, 0) << endl;

	return 0;

}