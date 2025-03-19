#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "hello";

	cout << str[0] << endl;
	cout << str[1] << endl;
	cout << str[2] << endl;
	cout << str[3] << endl;
	cout << str[4] << endl;

	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i] << " ";
	}

	cout << endl;


	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}

	cout << endl;

	return 0;
}