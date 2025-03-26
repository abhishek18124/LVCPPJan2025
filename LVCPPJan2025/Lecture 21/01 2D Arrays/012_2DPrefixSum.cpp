/*

e.g.

input

5 5 3

2 3 0 1 5
4 7 9 3 2
6 8 1 0 4
9 5 4 2 3
0 6 8 6 1

0 0 1 1
1 2 3 4
2 0 4 1

output

16
28
34

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int m, n, q;
	cin >> m >> n >> q;

	vector<vector<int>> arr(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> psum2D(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			psum2D[i][j] = arr[i][j];
			if (i > 0) psum2D[i][j] += psum2D[i - 1][j];
			if (j > 0) psum2D[i][j] += psum2D[i][j - 1];
			if (i > 0 and j > 0) psum2D[i][j] -= psum2D[i - 1][j - 1];
			// psum2D[i][j] = psum2D[i - 1][j] +
			//                psum2D[i][j - 1] -
			//                psum2D[i - 1][i - 1] +
			//                arr[i][j];
			// cout << psum2D[i][j] << " ";
		}
		// cout << endl;
	}

	while (q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		// find the sum of the submatrix whose top-left corner
		// is (l1, r1) and bottom-right corner is (l2, r2)

		int ans = psum2D[l2][r2];
		if (r1 > 0) ans -= psum2D[l2][r1 - 1];
		if (l1 > 0) ans -= psum2D[l1 - 1][r2];
		if (l1 > 0 and r1 > 0) ans += psum2D[l1 - 1][r1 - 1];

		// int ans = psum2D[l2][r2] -
		//           psum2D[l2][r1 - 1] -
		//           psum2D[l1 - 1][r2] +
		//           psum2D[l1 - 1][r1 - 1];

		cout << ans << endl;

	}

	return 0;
}