#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 1;
	int num = 1;

	while (i <= n) {

		// for the ith row, print i nos. starting from 1 in the inc. order

		int j = 1;

		while (j <= i) {
			cout << num << " ";
			num++;
			j++;
		}

		i++;

		cout << endl;

	}

	return 0;
}