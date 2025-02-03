#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;
	cin >> n;

	int lsf = INT_MIN; // to track the "largest so far"
	int ssf = INT_MAX; // to track the "smallest so far"

	int i = 1;

	while (i <= n) {

		int x;
		cin >> x;

		// if (x > lsf) {
		// 	lsf = x;
		// }

		lsf = max(lsf, x);

		// if (x < ssf) {
		// 	ssf = x;
		// }

		ssf = min(ssf, x);

		i = i + 1;

	}

	cout << lsf << " " << ssf << endl;

	cout << max(2, max(3, max(4, 5))) << endl;
	cout << min(2, min(3, min(4, 5))) << endl;
	// cout << max({2, 3, 4, 5}) << endl;
	// cout << min({2, 3, 4, 5}) << endl;

	return 0;
}