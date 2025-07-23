/*

given an integer 'inp' as a string, design an algorithm to find
total sum of digits of all the non-negative numbers upto 'inp'.

*/

#include<iostream>

using namespace std;

string inp = "2354";
string out = "";
int total = 0; // to track the sum of digit sums of all the non-negative numbers upto 'inp'

void f(int i, bool isPrefixSame, int digitSum) {

	// base case

	if (i == inp.size()) {
		cout << "digitSum(" << out << ") = " << digitSum << endl;
		total += digitSum;
		return;
	}

	// recursive case

	int upperBound = isPrefixSame ? inp[i] - '0' : 9;

	for (int d = 0; d <= upperBound; d++) {
		out.push_back(d + '0');
		f(i + 1, isPrefixSame and d == upperBound, digitSum + d);
		out.pop_back();
	}

}

int main() {

	f(0, true, 0);

	cout << total << endl;

	return 0;
}