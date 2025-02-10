#include<iostream>

using namespace std;

int main() {

	int n = 7;
	int cnt = 0; // to track the no. of set bits in 'n'

	while (n > 0) {

		if (n & 1) {
			cnt++;
		}

		n = n >> 1;

	}

	cout << cnt << endl;

	return 0;
}