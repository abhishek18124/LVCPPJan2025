#include<iostream>
#include<algorithm>

using namespace std;

bool isPresent(int mat[][3], int m, int n, int t) {

	for (int i = 0; i < m; i++) {

		// use binary search to search for the 't' in the ith row

		if (binary_search(mat[i], mat[i] + n, t)) {
			// 't' is found in the ith row
			return true;
		}

	}

	// 't' is not found
	return false;

}

int main() {

	int mat[][3] = {
		{40, 50, 60},
		{10, 20, 30},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	int t = 90;

	isPresent(mat, m, n, t) ? cout << t << " found" << endl :
	                               cout << t << " not found" << endl;


	return 0;
}