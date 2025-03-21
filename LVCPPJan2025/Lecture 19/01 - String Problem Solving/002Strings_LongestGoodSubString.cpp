#include<iostream>
#include<string>

using namespace std;

bool isGoodString(const string& str) { // we are passing str by ref to avoid copy which can expensive

	for (char ch : str) {
		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is consonant
			return false;
		}
	}

	// str is good
	return true;
}

// time : O(n^3)

int longestGoodSubstring(const string& str) {

	int maxSofar = 0; // to track the length of the longest good substring
	int n = str.size();

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// check if the substring that starts at the ith index
			// and ends at the jth index is a good substring or not ?
			string subString = str.substr(i, j - i + 1);
			if (isGoodString(subString)) {
				maxSofar = max(maxSofar, j - i + 1);
			}
		}
	}

	return maxSofar;

}

int main() {

	string str = "cbaeicdeiou";

	cout << longestGoodSubstring(str) << endl;

	return 0;
}