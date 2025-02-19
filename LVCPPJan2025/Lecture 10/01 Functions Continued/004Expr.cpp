#include<iostream>

using namespace std;

int c = 1;

int f() {
	return c;
}

int main() {

	// int x;
	// x = 2;
	// 2 = x;

	f() = 0;
	cout << c << endl;

	return 0;
}