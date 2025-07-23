/*

given an integer inp as a string, design a recursive algorithm
to enumerate all non-negative numbers digit-wise upto inp.

*/

#include<iostream>

using namespace std;

string inp = "9999";
int n;
string out = "";

void f(int i) {

	// base case

	if (i == n) {
		cout << out << endl;
		return;
	}

	// recursive case

	// decide the ith digit of the out[]

	for (int d = 0; d <= 9; d++) {
		out.push_back(d + '0');
		f(i + 1);
		out.pop_back(); // backtracking
	}

}

int main() {

	n = inp.size();

	f(0);

	return 0;
}