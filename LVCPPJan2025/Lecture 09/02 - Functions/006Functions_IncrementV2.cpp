#include<iostream>

using namespace std;

int inc(int a) {
	a++;
	return a;
}

int main() {

	int a = 10;

	cout << a << endl;

	a = inc(a);

	cout << a << endl;

	return 0;
}