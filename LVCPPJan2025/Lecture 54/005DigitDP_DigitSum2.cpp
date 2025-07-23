/*

given an integer 'inp' as a string, design an algorithm to find
total sum of digits of all the non-negative numbers upto 'inp'.

*/

#include<iostream>

using namespace std;

string inp = "2354";
int n;

int f(int i, bool isPrefixSame, int digitSum) {

	// base case

	if (i == n) {
		return digitSum;
	}

	// recursive case

	int upperBound = isPrefixSame ? inp[i] - '0' : 9;
	int total = 0;

	for (int d = 0; d <= upperBound; d++) {

		total += f(i + 1, isPrefixSame and d == upperBound, digitSum + d);

	}

	return total;

}

int main() {

	n = inp.size();

	cout << f(0, true, 0) << endl;

	return 0;
}