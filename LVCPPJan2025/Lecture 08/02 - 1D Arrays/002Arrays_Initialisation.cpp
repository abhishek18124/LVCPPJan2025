#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int A[5] = {10, 20, 30, 40, 50};
	int n = sizeof(A) / sizeof(int);

	// cout << A[0] << endl;
	// cout << A[1] << endl;
	// cout << A[2] << endl;
	// cout << A[3] << endl;
	// cout << A[4] << endl;

	for (int i = 0; i < n; i++) {
		cout << A[i] << endl;
	}

	cout << endl;

	int B[] = {100, 200, 300}; // specifying size of the array during init. is optional
	int m = sizeof(B) / sizeof(int);

	for (int i = 0; i < m; i++) {
		cout << B[i] << endl;
	}

	cout << endl;

	int C[5] = {1000, 2000, 3000};
	int k = sizeof(C) / sizeof(int);

	for (int i = 0; i < k; i++) {
		cout << C[i] << endl;
	}

	// int D[5] = {1, 2, 3, 4, 5, 6}; // error

	int E[10] = {};

	for (int i = 0; i < 10; i++) {
		cout << E[i] << " ";
	}

	cout << endl;

	int F[10] = {0};

	for (int i = 0; i < 10; i++) {
		cout << F[i] << " ";
	}

	cout << endl;

	int G[10];

	for (int i = 0; i < 10; i++) {
		G[i] = 1;
	}

	for (int i = 0; i < 10; i++) {
		cout << G[i] << " ";
	}

	cout << endl;

	int H[10];

	memset(H, 0, sizeof(H));

	for (int i = 0; i < 10; i++) {
		cout << H[i] << " ";
	}

	cout << endl;

	int I[10];

	memset(I, -1, sizeof(I));

	for (int i = 0; i < 10; i++) {
		cout << I[i] << " ";
	}

	cout << endl;

	return 0;
}