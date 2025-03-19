#include<iostream>
#include<string>

using namespace std;

// a string of size n has n(n+1)/2 ~ n^2 substrings

void generateSubstrings(string str) { // str is by default passed by value i.e. its copy is sent during the fn call
	int n = str.size();
	for (int i = 0; i <= n - 1; i++) {
		for (int j = i; j <= n - 1; j++) {
			// generate the substring that starts at the
			// ith index and ends at the jth index
			string subString = str.substr(i, j - i + 1);
			cout << subString << endl;
		}
		cout << endl;
	}
}

int main() {

	string str = "abcde";
	int n = str.size();

	generateSubstrings(str); // sending copy of a string (default behv.) is expensive

	return 0;
}