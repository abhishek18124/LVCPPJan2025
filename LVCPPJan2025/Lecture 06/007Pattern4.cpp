#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 1;

	while (i <= n) {

		// for the ith row, print i nos.

		int j = 1;
		int num = (i % 2 == 0) ? 0 : 1;

		while (j <= i) {

			cout << num;

			// if (num == 1) {
			// 	num = 0;
			// } else {
			// 	num = 1;
			// }

			// num = !num;

			num = 1 - num;

			j++;

		}

		i++;

		cout << endl;

	}

	return 0;
}