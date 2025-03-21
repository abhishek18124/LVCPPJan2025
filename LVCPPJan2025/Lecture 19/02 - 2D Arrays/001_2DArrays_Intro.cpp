/*

	Constraints

	0 < m, n <= 10

	here, m denotes the no. of rows in the given 2D array
	      n denotes the no. of cols in the given 2D array

*/

#include<iostream>

using namespace std;

int main() {

	// int a[3][4];
	// cout << sizeof(a) << endl;

	// char b[4][5];
	// cout << sizeof(b) << endl;

	// double c[6][7];
	// cout << sizeof(c) << endl;

	int arr[10][10];

	int m;
	cin >> m;

	int n;
	cin >> n;

	// read mxn values into the 2D array

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	// print mxn values of the 2D array

	for (int i = 0; i < m; i++) {
		// print the ith row
		for (int  j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}


