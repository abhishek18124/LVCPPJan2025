#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1; // here, we've declared a string object
	s1 = "abc"; // here, we've assign the string literal "abc" to s1
	cout << s1 << endl;
	cout << "len(" << s1 << ") = " << s1.length() << endl;
	cout << "len(" << s1 << ") = " << s1.size() << endl;

	string s2 = "coding"; // here, we've initialised a string obj
	cout << s2 << endl;
	cout << "len(" << s2 << ") = " << s2.size() << endl;
	cout << s2[0] << endl;
	cout << s2[1] << endl;

	for (int i = 0; i < s2.size(); i++) {
		cout << s2[i] << " ";
	}
	cout << endl;

	for (int i = 0; s2[i] != '\0'; i++) {
		cout << s2[i] << " ";
	}
	cout << endl;

	return 0;
}