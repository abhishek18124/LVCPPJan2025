/*

https://codeforces.com/problemset/problem/276/C

e.g.

input
3 3
5 3 2
1 2
2 3
1 3

output
25

input
5 3
5 2 4 1 3
1 5
2 3
2 3

output
33

*/

#include<iostream>
#include<vector>
#include<algorithm>

#define int long long

using namespace std;

int32_t main() {

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> diff(n + 1, 0);
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--; r--; // since unlike cf, we are using 0-based indexing
		diff[l] += 1;
		diff[r + 1] -= 1;
	}

	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << diff[i] << " ";
	// }

	// cout << endl;

	sort(a.begin(), a.end());
	sort(diff.begin(), diff.end() - 1);

	int maxSum = 0;
	for (int i = 0; i < n; i++) {
		maxSum += a[i] * diff[i];
	}

	cout << maxSum << endl;


	return 0;
}