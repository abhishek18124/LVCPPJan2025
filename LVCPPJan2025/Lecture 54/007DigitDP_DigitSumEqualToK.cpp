/*

given an integer inp as a string, design a recursive algorithm to find count
of all the non-negative numbers up to inp whose sum of digits is equal to K.


constraints :
	inp <= 1e18
	k <= 200

*/

#include<iostream>

using namespace std;

string inp;
int n;
int k;

int f(int i, bool isPrefixSame, int digitSum) {

	// base case

	if (i == n) {

		if (digitSum == k) { // you've built a an out which is valid i.e. it has a digitSum of k
			return 1;
		} else { // you've built a an out which is not valid i.e. digitSum is not equal to k
			return 0;
		}

	}

	// recursive case

	int upperBound = isPrefixSame ? inp[i] - '0' : 9;

	int cnt = 0;

	for (int d = 0; d <= upperBound; d++) {

		cnt += f(i + 1, isPrefixSame and d == upperBound, digitSum + d);

	}

	return cnt;

}

int main() {

	cin >> inp >> k;

	n = inp.size();

	cout << f(0, true, 0) << endl;

	return 0;
}