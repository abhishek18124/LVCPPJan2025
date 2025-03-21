#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(const string& s) { // const& to avoid copy
	int i = 0;
	int j = s.size() - 1;
	while (i < j) {
		if (s[i] != s[j]) {
			return false; // s[] cannot be a palindrome
		}
		i++;
		j--;
	}
	return true; // s[] is a palindrome
}

// time : O(n^3)
// space: O(1)

int countPalindromicSubstrings(const string& s) { // const& to avoid copy

	int cnt = 0; // to track the no. of palindromic substrings in the given string
	int n = s.size();

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// check if the substring that starts at the ith index
			// and ends at the jth index is a palindromic or not ?
			string subString = s.substr(i, j - i + 1);
			if (isPalindrome(subString)) {
				cnt++;
			}
		}
	}

	return cnt;

}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstrings(s) << endl;

	return 0;
}