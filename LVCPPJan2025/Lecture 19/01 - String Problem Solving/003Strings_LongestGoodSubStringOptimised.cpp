#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "cbaeicdeiou";

	// time : O(n)

	// [HW] try to print the longest good substring

	int maxSofar = 0; // to track the length of the longest good substring
	int cnt = 0;

	for (char ch : str) {

		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			// ch is a vowel
			cnt++;
			maxSofar = max(maxSofar, cnt);
		} else {
			// maxSofar = max(maxSofar, cnt);
			cnt = 0;
		}

	}

	// maxSofar = max(maxSofar, cnt);
	cout << maxSofar << endl;

	return 0;
}