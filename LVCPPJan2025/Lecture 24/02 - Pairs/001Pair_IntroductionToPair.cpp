/*
		https://cplusplus.com/reference/utility/pair/?kw=pair

		This 'pair' class couples together a pair of values, which maybe of different
		types (T1 and T2).The individual values of a pair can be accessed through its
		public members first and second.
*/

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main() {

	// 1. declaring an object of the 'pair' class or creating a variable of the 'pair' type

	pair<int, int> p1; 	     // 'p1' is a pair to store a 'pair of integers'

	cin >> p1.first >> p1.second;

	cout << p1.first << " " << p1.second << endl;

	pair<string, string> p2; // 'p2' is a pair to store a 'pair of strings'

	p2.first = "hello";
	p2.second = "world";

	cout << p2.first << " " << p2.second << endl;

	pair<string, int> p3;    // 'p3' is a pair to store a 'pair with a string & an integer'

	// 2. initialising a pair i.e. assigning initial values upon declaration

	pair<int, int> p4(1, 2); // 'p4' is a pair which stores integers (1, 2)

	pair<string, string> p5("india", "delhi"); // 'p5' is a pair which stores strings ("india", "delhi")

	pair<string, int> p6("india", 1947); // 'p6' is a pair which stores ("india", 1947)

	// 3. accessing pair elements using 'first' and 'second' data members

	cout << "(" << p4.first << ", " << p4.second << ")" << endl  // (1, 2)
	     << "(" << p5.first << ", " << p5.second << ")" << endl  // (india, delhi)
	     << "(" << p6.first << ", " << p6.second << ")" << endl; // (india, 1947)

	// 4. creating a pair using the make_pair() function

	pair<char, int> p7 = make_pair('A', 1);

	cout << "(" << p7.first << ", " << p7.second << ")" << endl; // (A, 1)

	vector<int> v;
	vector<pair<int, int>> v3;

	v3.push_back(make_pair(1, 1));
	v3.push_back(make_pair(3, 4));
	v3.push_back({5, 6});

	for (pair<int, int> p : v3) {
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}