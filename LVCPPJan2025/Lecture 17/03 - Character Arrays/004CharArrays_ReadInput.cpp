// n <= 100

#include<iostream>

using namespace std;

// n <= 5

int main() {

	char str[101]; // based on constraints

	// cin >> ignores leading whitespaces
	// cin >> stopes at 1st non-leading whitespace

	cin >> str; // cin >> stops reading i/p string as soon as you encounter a whitespace

	// cin.getline(str, 101); // '\n' is default delimiting char

	// cin.getline(str, 5, '\n');

	// cin.getline(str, 101, '$');

	// cin.getline(str, 5, '$');

	cout << str << endl;

	return 0;
}