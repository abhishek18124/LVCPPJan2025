/*

given an integer inp as a string, design a recursive algorithm
to enumerate all non-negative numbers digit-wise upto inp.

*/

#include<iostream>

using namespace std;

string inp = "2354";
int n;
string out = "";

void f(int i) {

	// base case

	if (i == n) {
		cout << out << endl;
		return;
	}

	// recursive case

	bool isPrefixSame = true;
	for (int j = 0; j < i; j++) {
		if (inp[j] != out[j]) {
			isPrefixSame = false;
			break;
		}
	}

	int upperBound = isPrefixSame ? inp[i] - '0' : 9;

	// decide the ith digit of the out[]

	for (int d = 0; d <= upperBound; d++) {
		out.push_back(d + '0');
		f(i + 1);
		out.pop_back();
	}

}

int main() {

	n = inp.size();

	f(0);

	return 0;
}