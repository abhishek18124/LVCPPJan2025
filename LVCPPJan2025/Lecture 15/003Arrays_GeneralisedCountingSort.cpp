/*

e.g.

input
10
4 3 2 2 4 3 5 4 5 2
2 5

output
2 2 2 3 3 4 4 4 5 5

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

	int l, r;
	cin >> l >> r;

	// 1. build freqMap - time : n.const ~ O(n)

	vector<int> freq(r - l + 1, 0);
	for (int x : arr) {
		freq[x - l]++;
	}

	// for (int i = 0; i <= r - l; i++) {
	// 	cout << freq[i] << " ";
	// }
	// cout << endl;

	// 2. use the freqMap to print the sorted array

	for (int i = 0; i <= r - l; i++) {

		// print i+l, freq[i] times

		for (int j = 1; j <= freq[i]; j++) {
			cout << i + l << " ";
		}

	}

	return 0;
}