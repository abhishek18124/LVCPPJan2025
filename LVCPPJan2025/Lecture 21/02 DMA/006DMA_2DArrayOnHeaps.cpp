#include<iostream>

using namespace std;

int main() {

	int m;
	cin >> m;

	int n;
	cin >> n;

	// create a 2D array of dimension 'mxn' on the heap memory

	int** ptr = new int*[m];

	// ptr[0] = new int[n];
	// ptr[1] = new int[n];
	// ...
	// ptr[m-1] = new int[n];

	for (int i = 0; i < m; i++) {
		ptr[i] = new int[n];
	}

	// read values into the 2D array

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ptr[i][j];
		}
	}

	// print value of the 2D array

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}

	// deallocate memory for 2D array

	for (int i = 0; i < m; i++) {
		delete [] ptr[i];
	}

	delete [] ptr;

	return 0;
}