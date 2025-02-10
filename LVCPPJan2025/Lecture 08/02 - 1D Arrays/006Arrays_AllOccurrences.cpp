// constraints n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[100]; // based on constraints

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int t;
	cin >> t;

	// time : O(n)

	int i;
	int cnt = 0;

	for (i = 0; i < n; i++) {
		if (arr[i] == t) {
			// you've found the first occ. of the 't' at index i
			cout << i << endl;
			cnt++;
		}
	}

	if (cnt == 0) {
		cout << -1 << endl;
	}

	return 0;
}