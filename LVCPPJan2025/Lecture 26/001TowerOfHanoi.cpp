#include<iostream>

using namespace std;

// total move = 2^n - 1

void f(int n, char src, char hlp, char dst) {

	// base case

	if (n == 0) {
		return;
	}

	// recursive case

	// 1. ask your friend to move n-1 disks from src (A) to hlp(B) using dst (C)

	f(n - 1, src, dst, hlp);

	// 2. move the largest disk from src (A) to dst (C)

	cout << "move disk from " << src << " to " << dst << endl;

	// 3. ask your friend to move n-1 disks from hlp(B) to dst(C) using src(A)

	f(n - 1, hlp, src, dst);

}

int main() {

	int n = 3;

	f(n, 'A', 'B', 'C');

	return 0;
}