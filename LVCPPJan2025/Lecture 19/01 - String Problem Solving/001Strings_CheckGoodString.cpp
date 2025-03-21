#include<iostream>
#include<string>

using namespace std;

// time : O(n) where n is the length of str

bool isGoodString(const string& str) { // we are passing str by ref to avoid copy which can expensive

	// for (int i = 0; str[i] != '\0'; i++) {
	// 	char ch = str[i];
	// 	if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
	// 		// ch is consonant
	// 		return false;
	// 	}
	// }

	for (char ch : str) {
		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is consonant
			return false;
		}
	}

	// str is good
	return true;
}

int main() {

	string str = "uoxea";

	isGoodString(str) ? cout << "good string" << endl :
	                         cout << "not good string" << endl;

	return 0;
}