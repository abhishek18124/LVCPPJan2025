#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int k = 3;

	int mask = 1 << k;

	int ans = n ^ mask;

	cout << ans << endl;

	n = 42;
	k = 4;

	mask = 1 << k;

	ans = n ^ mask;

	cout << ans << endl;

	return 0;
}