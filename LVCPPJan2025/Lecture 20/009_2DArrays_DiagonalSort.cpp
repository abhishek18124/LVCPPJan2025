/*

	constraints :

	0 < m, n <= 10

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// max. length of the diagonal = min(m, n) = x
// sorting will take xlogx time

void sortDiagonal(int mat[][10], int m, int n, int i, int j) {

	// sort the diagonal of the given mat[][] that starts at the i,jth index

	int dlen = min(m - i, n - j);
	vector<int> diagonal(dlen);
	for (int k = 0; k < dlen; k++) {
		diagonal[k] = mat[i + k][j + k];
	}

	// vector<int> diagonal;
	// for (int k = 0; k < dlen; k++) {
	// 	diagonal.push_back(mat[i + k][j + k]);
	// }

	sort(diagonal.begin(), diagonal.end());

	for (int k = 0; k < dlen; k++) {
		mat[i + k][j + k] = diagonal[k];
	}

}

// how many diagonals are present in an matrix of size mxn ? m+n-1 ~ m+n
// total time = no. of diagonals * time to sort each diagonal
// (m+n) * (x + xlogx + x)
// (m+n) * xlogx

void sortMatrixDiagonally(int mat[][10], int m, int n) {

	// iterate over diagonal starting points

	// (0, j)

	for (int j = 0; j < n; j++) {
		sortDiagonal(mat, m, n, 0, j);
	}

	// (i, 0)
	for (int i = 1; i < m; i++) {
		sortDiagonal(mat, m, n, i, 0);
	}

}

int main() {

	int mat[10][10] = {
		{50, 80, 20},
		{90, 10, 70},
		{60, 30, 40}
	};

	int m = 3;
	int n = 3;

	sortMatrixDiagonally(mat, m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}