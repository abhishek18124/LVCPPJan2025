#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "acbdcdef";

	cout << str.substr(2, 4) << endl; // 2nd arg. optional
	cout << str.substr(2) << endl;
	// cout << str.substr(2, 100) << endl;

	return 0;
}