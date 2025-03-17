#include<iostream>
#include<cstring>

using namespace std;

int findLength(char str[]) {
	int cnt = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		cnt++;
	}
	return cnt;
}

int main() {

	char str[] = "coding";

	// cout << (sizeof(str) / sizeof(char)) - 1 << endl; // may not always work

	cout << findLength(str) << endl;
	cout << strlen(str) << endl;

	char str2[100];
	cin >> str2;

	// cout << (sizeof(str2) / sizeof(char)) - 1 << endl; // may not always work
	cout << findLength(str2) << endl;
	cout << strlen(str2) << endl;

	return 0;
}