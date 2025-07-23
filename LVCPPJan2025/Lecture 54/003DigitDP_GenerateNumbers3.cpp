/*

given an integer inp as a string, design a recursive algorithm
to enumerate all non-negative numbers digit-wise upto inp.

*/

#include<iostream>

using namespace std;

string inp = "1234";
string out = "";

void f(int i, bool isPrefixSame) {

	// base case

	if (i == inp.size()) {
		cout << out << endl;
		return;
	}

	// recursive case

	int upperBound = isPrefixSame ? inp[i] - '0' : 9;

	for (int d = 0; d <= upperBound; d++) {
		out.push_back(d + '0');
		f(i + 1, isPrefixSame and d == upperBound);
		out.pop_back();
	}

}

int main() {

	f(0, true);

	return 0;
}