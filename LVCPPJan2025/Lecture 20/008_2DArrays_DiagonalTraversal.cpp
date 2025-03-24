/*

	constraints :

	0 < m, n <= 10

*/

#include<iostream>

using namespace std;

void printDiagonal(int mat[][10], int m, int n, int i, int j) {

	// print the diagonal of the given mat[][] that starts at the i,jth index

	int dlen = min(m - i, n - j);

	for (int k = 0; k < dlen; k++) {
		cout << mat[i + k][j + k] << " ";
	}

	cout << endl;

	// while (i <= m - 1 and j <= n - 1) {
	// 	cout << mat[i][j] << " ";
	// 	i++;
	// 	j++;
	// }

	// cout << endl;

}

void diagonalTraversal(int mat[][10], int m, int n) {

	// iterate over diagonal starting points

	// (0, j)

	for (int j = 0; j < n; j++) {
		printDiagonal(mat, m, n, 0, j);
	}

	// (i, 0)
	for (int i = 1; i < m; i++) {
		printDiagonal(mat, m, n, i, 0);
	}

}

int main() {

	int mat[10][10] = {
		{11, 12, 13, 14},
		{15, 16, 17, 18},
		{19, 20, 21, 22}
	};

	int m = 3;
	int n = 4;

	diagonalTraversal(mat, m, n);

	return 0;
}