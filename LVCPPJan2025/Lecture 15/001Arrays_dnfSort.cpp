/*

e.g.

input
9
1 0 1 2 0 1 2 0 1

output
0 0 0 1 1 1 1 2 2

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// time : O(n)
	// space: O(1)

	int low = 0;
	int mid = 0;
	int high = n - 1;

	while (mid <= high) {

		if (arr[mid] == 0) {
			// put arr[mid] in region of zeros
			swap(arr[mid], arr[low]);
			low++;
			mid++;
		} else if (arr[mid] == 1) {
			// put arr[mid] in region of ones
			mid++;
		} else {
			// arr[mid] == 2
			// put arr[mid] in region of twos
			swap(arr[mid], arr[high]);
			high--;
		}

	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;

}