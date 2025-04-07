#include<iostream>

using namespace std;

// time : O(n^2)
// space: O(n^2) since each stack frame has its own string obj

int f(string s, int n) {

	// base case
	if (s.empty()) { // s == "" // n == 0
		return 0;
	}

	// recursive case

	// 1. ask your friend to convert the substring that starts
	// at index 0 and has a length n-1 to an integer

	string subString = s.substr(0, n - 1);
	int integerFromMyFriend = f(subString, n - 1);

	return integerFromMyFriend * 10 + (s[n - 1] - '0');

}

int main() {

	string s = "12345";
	int n = s.size();

	cout << f(s, n) << endl;

	return 0;
}