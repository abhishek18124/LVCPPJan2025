#include<iostream>

using namespace std;

void mySwap(int& x, int& y) { // x, and y are references (new names) to a, and b
	int temp = x;
	x = y;
	y = temp;
}

int main() {

	int a = 10;
	int b = 20;

	cout << a << " " << b << endl;

	mySwap(a, b);

	cout << a <<  " " << b << endl;

	int c = 100;
	int d = 200;

	cout << c << " " << d << endl;

	mySwap(c, d);

	cout << c << " " << d << endl;

	return 0;
}