#include<iostream>

using namespace std;

int multiply(int a, int b) {
	// int c = a * b;
	// return c;
	return a * b;
}


int main() {

	cout << multiply(2, 3) << endl;

	cout << multiply(4, 5) + 10 << endl;

	int ans = multiply(10, 20);

	ans++;

	cout << ans << endl;

	return 0;
}