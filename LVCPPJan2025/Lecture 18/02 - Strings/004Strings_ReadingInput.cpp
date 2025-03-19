#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1;
	cin >> s1; // cin >> stops at 1st non-leading whitespace
	// cin >> ignores leading whitespaces
	cout << s1 << endl;

	return 0;
}