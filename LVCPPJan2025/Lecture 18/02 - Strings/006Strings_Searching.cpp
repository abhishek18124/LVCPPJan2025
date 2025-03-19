#include<iostream>
#include<string>
#include<climits>

using namespace std;

int main() {

	string s = "abcbcbcd";
	string t = "cb";

	cout << s.size() << endl;

	cout << s.find(t) << endl; // returns starting index of 1st occ. of t in s
	cout << s.rfind(t) << endl; // return starting index of last occ. of t in s

	string w = "xy";
	cout << s.find(w) << endl;

	if (s.find(w) == string::npos) {
		cout << w << " is not present in " << s << endl;
	}

	cout << string::npos << endl;

	// int32_t
	// int64_t
	// size_t // a var. of this type is used for storing unsigned integers i.e. non-negative integers i.e >= 0
	// what is the range of size_t
	// 0 to 2^(64-1)
	// what does the binary of 2^(64-1) look like ? 1111....1

	// what does the binary of -1 look like ? 1111....1

	// cout << sizeof(size_t) << endl;
	// cout << ULLONG_MAX << endl;

	return 0;
}