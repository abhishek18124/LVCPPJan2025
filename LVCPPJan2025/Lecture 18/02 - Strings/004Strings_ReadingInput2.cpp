#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {

	string s1;
	// getline(cin, s1); // stops reading as soon as it encounter '\n'
	// getline(cin, s1, '$'); // stops reading as soon as it encounter '$'
	// getline(cin, s1); // getline() also reads leading whitespaces
	getline(cin >> ws, s1); // we are 'ws' which is an input manipular while reading the i/p, and what it does is, it ignores leading whitespaces
	cout << s1 << endl;

	return 0;
}