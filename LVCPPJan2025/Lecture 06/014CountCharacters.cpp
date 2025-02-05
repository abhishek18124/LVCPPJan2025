#include<iostream>

using namespace std;

int main() {

	int cnt = 0; // to track the no. of characters

	char ch;

	while (true) {

		// cin >> ch; // cin >> ignores whitespaces (' ', '\n', '\t')
		ch = cin.get(); // cin.get() is used if you want to read whitespace characters as well

		if (ch == '$') {
			break;
		}

		cnt++;

	}

	cout << "cnt = " << cnt << endl;

	return 0;
}