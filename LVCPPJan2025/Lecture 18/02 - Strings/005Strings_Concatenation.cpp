#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "abc";
	string s2 = "def";

	s1.append(s2);

	cout << s1 << endl;
	cout << s2 << endl;

	string s3 = "uvw";
	string s4 = "xyz";

	s3 = s3 + s4; // use this over append(...)

	cout << s3 << endl;
	cout << s4 << endl;

	string str = "codin";
	str.push_back('g');
	cout << str << endl;
	str.pop_back();
	cout << str << endl;

	string s = "abc";
	cout << s[0] << " " << s.front() << endl;
	cout << s[s.size() - 1] << " " << s.back() << endl;

	string t;
	cout << t.size() << endl;
	if (t.size() == 0) {
		cout << "t is empty" << endl;
	}
	if (t == "") {
		cout << "t is empty" << endl;
	}
	if (t.empty()) {
		cout << "t is empty" << endl;
	}

	string w = "zoom";
	cout << w.size() << endl;
	w.clear();
	cout << w.size() << endl;

	return 0;
}