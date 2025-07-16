/*

https://codeforces.com/problemset/problem/1842/C

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// time : O(n^n)
// space: O(n) due to function call stack

int f(vector<int>& a, int n, int i) {

	// base case

	if (i == n) {
		// f(n) = find the max. no. of balls tenzing can remove from a[n...n-1] = {}
		return 0;
	}

	// recursive case

	// f(i) = find the max. no. of balls tenzing can remove from a[i...n-1]

	// decide for the ith ball

	// option 1 : don't remove the ith ball

	int dontRemoveOption = f(a, n, i + 1);

	// option 2 : remove the ith ball

	int removeOptionMaxSoFar = INT_MIN;

	for (int j = i + 1; j < n; j++) {
		if (a[j] == a[i]) {
			removeOptionMaxSoFar = max(removeOptionMaxSoFar, (j - i + 1) + f(a, n, j + 1));
		}
	}

	return max(dontRemoveOption, removeOptionMaxSoFar);

}

// time : O(n^2)
// space: O(n)

int fBottomUp(vector<int>& a, int n) {

	vector<int> dp(n + 1);

	dp[n] = 0; // at the nth index of dp[] we store f(n)

	for (int i = n - 1; i >= 0; i--) {

		// dp[i] = f(i)

		// f(i) = find the max. no. of balls tenzing can remove from a[i...n-1]

		// decide for the ith ball

		// option 1 : don't remove the ith ball

		int dontRemoveOption = dp[i + 1];

		// option 2 : remove the ith ball

		int removeOptionMaxSoFar = INT_MIN;

		for (int j = i + 1; j < n; j++) {
			if (a[j] == a[i]) {
				removeOptionMaxSoFar = max(removeOptionMaxSoFar, (j - i + 1) + dp[j + 1]);
			}
		}

		dp[i] = max(dontRemoveOption, removeOptionMaxSoFar);
	}

	return dp[0]; // at the 0th index of dp[] we store f(0)

}

// time : O(n)
// space: O(n)

int fBottomTimeOptimised(vector<int>& a, int n) {

	vector<int> dp(n + 1);

	dp[n] = 0; // at the nth index of dp[] we store f(n)

	vector<int> cm(n + 1, -1); // here we are using array as a map since we know colors range from 1 to n

	// at index 1 we store the position where we last saw color 1
	// at index 2 we store the position where we last saw color 2
	// at index 3 we store the position where we last saw color 3
	// ..
	// at index n we store the position where we last saw color n

	for (int i = n - 1; i >= 0; i--) {

		// dp[i] = f(i)

		// f(i) = find the max. no. of balls tenzing can remove from a[i...n-1]

		// decide for the ith ball

		// option 1 : don't remove the ith ball

		int dontRemoveOption = dp[i + 1];

		// option 2 : remove the ith ball

		int c = a[i];

		int j = cm[c];

		int removeOptionMaxSoFar = j == -1 ? INT_MIN : max(j - i + 1 + dp[j + 1], (j - i) + dp[j]);

		dp[i] = max(dontRemoveOption, removeOptionMaxSoFar);

		cm[c] = i;

	}

	return dp[0]; // at the 0th index of dp[] we store f(0)

}

int main() {

	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		// cout << f(a, n, 0) << endl;

		// cout << fBottomUp(a, n) << endl;

		cout << fBottomTimeOptimised(a, n) << endl;

	}

	return 0;
}
