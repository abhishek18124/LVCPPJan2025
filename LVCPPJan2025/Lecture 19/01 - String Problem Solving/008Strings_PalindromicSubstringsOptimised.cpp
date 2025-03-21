#include<iostream>
#include<string>

using namespace std;

// time : O(n^2)
// space: O(1)

int countPalindromicSubstrings(const string& s) {

	int n = s.size();
	int cnt = 0; // to track the no. of palindromic substrings in the given string

	// 1. find out no. of odd-len palindromic substrings in s

	for (int i = 0; i < n; i++) {

		// find out no. of odd-len palindromic substrings with s[i] as the center

		int j = 0;
		while (i + j <= n - 1 and i - j >= 0 and s[i - j] == s[i + j]) {
			cnt++;
			j++;
		}

	}

	// 2. find out no. of even-len palindromic substrings in s

	for (double i = 0.5; i < n; i++) {

		// find out no. of even-len palindromic substrings with ith center

		double j = 0.5;
		while (i + j <= n - 1 and i - j >= 0 and s[(int)(i - j)] == s[(int)(i + j)]) {
			cnt++;
			j++;
		}

	}

	return cnt;

}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstrings(s) << endl;

	return 0;
}