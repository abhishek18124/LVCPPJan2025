#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b
// otherwise return false

bool cmp(string a, string b) { // param are of string type since we are dealing with arr[] of strings and at any point of time we'll compare two strings
	// if (a.size() < b.size()) {
	// 	// we want a to be placed before b since we are sorting length-wise in inc. order
	// 	return true;
	// }
	// return false;
	return a.size() < b.size();
}

int main() {

	string arr[] = {"abcd", "wxy", "z", "ef"};
	int n = 4;

	sort(arr, arr + n); // arr[] is by default sorted in lexicographically inc. order

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	sort(arr, arr + n, greater<string>()); // here arr[] is by default sorted in lexicographically dec. order


	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// sort arr[] length-wise in inc. order

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}