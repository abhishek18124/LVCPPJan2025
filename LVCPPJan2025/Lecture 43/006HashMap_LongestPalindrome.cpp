#include<iostream>
#include<vector>
#include<set>

using namespace std;

// time : nlogn since we are using set<>
// time : on avg. O(n) since we are using unordered_set<> but worst case O(n^2)
// space: O(n) due set<> / unordered_set<>

int longestPalindrome(string& str) {

	set<char> s;

	int ans = 0;

	for (char ch : str) {
		if (s.find(ch) == s.end()) {
			s.insert(ch);
		} else {
			ans += 2;
			s.erase(ch);
		}
	}

	if (s.size() > 0) ans++;

	return ans;

}

int main() {

	string str = "abccccdd";

	cout << longestPalindrome(str) << endl;

	return 0;
}