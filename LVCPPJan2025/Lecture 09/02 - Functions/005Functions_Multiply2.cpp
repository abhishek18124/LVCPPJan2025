#include<iostream>

using namespace std;

int multiply(int x, int y) {
	int c = x * y;
	return c; // return by value // we are sending back copy of c
}

int main() {

	int a = 10;
	int b = 20;

	cout << multiply(a, b) << endl; // pass by value // we are sending copies of a and b

	return 0;
}