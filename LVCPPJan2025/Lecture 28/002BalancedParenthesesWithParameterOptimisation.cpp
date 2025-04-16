// n <= 8

#include<iostream>

using namespace std;

void f(int n, char out[], int oc, int cc) {

	int i = oc + cc;

	// base case

	if (i == 2 * n) {
		out[i] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case

	// f(i, oc, cc) = take decisions for the remaining positions i to 2n-1 s.t.
	// you've used oc '(' and cc '('

	// decide for position i

	// option 1 : use '('

	if (oc < n) {
		out[i] = '(';
		f(n, out, oc + 1, cc);
	}

	// option 2 : use ')'

	if (cc < oc) {
		out[i] = ')';
		f(n, out, oc, cc + 1);
	}

}

int main() {

	int n = 2;

	char out[17]; // based on constraints

	f(n, out, 0, 0);

	return 0;
}