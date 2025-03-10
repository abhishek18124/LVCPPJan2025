/*

e.g.

input
9
1 0 3 2 3 1 2 0 2
3

output
0 0 1 1 2 2 2 3 3

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

	int k;
	cin >> k;

	// time : O(n)
	// space: O(k) due to freq[]

	// 1. build freqMap - time : n.const ~ O(n)

	vector<int> freq(k + 1, 0);
	for (int x : arr) {
		freq[x]++;
	}

	for (int i = 0; i <= k; i++) {
		cout << "freq[" << i << "] = " << freq[i] << endl;
	}

	// 2. use the freqMap to print the sorted array

	// time : n.const ~ O(n)

	for (int i = 0; i <= k; i++) {

		// print i, freq[i] times

		// i = 0, print 0, freq[0] times i.e. 2 times
		// i = 1, print 1, freq[1] times i.e. 2 times
		// i = 2, print 2, freq[2] times i.e. 3 times
		// i = 3, print 3, freq[3] times i.e. 2 times

		for (int j = 1; j <= freq[i]; j++) {
			cout << i << " ";
		}

	}


	return 0;
}