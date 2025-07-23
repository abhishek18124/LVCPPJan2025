/*

given an integer 'inp' as a string, design an algorithm to find
total sum of digits of all the non-negative numbers upto 'inp'.

constraints :
	inp <= 1e18

*/

#include<iostream>
#include<cstring>

using namespace std;

string inp = "2354";
int n;
int dp[20][2][200];

// time = no. of unique subproblems * time spent on each subproblem = (20 * 2 * 164) * 10 = (6560) * 10 = 65600 ~ 6 * 10^4
// space = n i.e. 20 due to fn call stack  + 20*2*164 = 20 + 6560 ~ 10^4

int f(int i, bool isPrefixSame, int digitSum) {

	// lookup
	if (dp[i][isPrefixSame][digitSum] != -1) {
		return dp[i][isPrefixSame][digitSum];
	}

	// base case

	if (i == n) {
		return dp[i][isPrefixSame][digitSum] = digitSum; // saving is optional
	}

	// recursive case

	int upperBound = isPrefixSame ? inp[i] - '0' : 9;
	int total = 0;

	for (int d = 0; d <= upperBound; d++) {

		total += f(i + 1, isPrefixSame and d == upperBound, digitSum + d);

	}

	return dp[i][isPrefixSame][digitSum] = total; // saving is mandatory

}


int main() {

	n = inp.size();

	memset(dp, -1, sizeof(dp));

	cout << f(0, true, 0) << endl;

	return 0;
}