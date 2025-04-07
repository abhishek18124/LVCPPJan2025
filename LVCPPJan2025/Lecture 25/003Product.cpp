#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case
	if (y == 0) {
		// f(x, 0) = find the product of x and 0
		return 0;
	}

	// recursive case

	// f(x, y) = find the product of x and y i.e. we want to know
	// what is the result when we add x, y times

	// 1. ask your friend to find the product of x and y-1 i.e. ask
	// your friend for the result we get when we add x, y-1 times

	int A = f(x, y - 1);
	return x + A;

}

int main() {

	int x = 12;
	int y = 9;

	if (x > y) {
		cout << f(x, y) << endl;
	} else {
		cout << f(y, x) << endl;
	}

	return 0;
}