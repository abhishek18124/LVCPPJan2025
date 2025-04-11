/*

	https://cplusplus.com/reference/set/set/?kw=set
	https://cplusplus.com/reference/set/multiset/?kw=multiset

	> insert/erase/find is logarithmic i.e. O(logn)
	> values are inserted in the sorted order
	> set contains only distinct values
	> multiset allows duplicate values

*/

#include<iostream>
#include<set>

using namespace std;

int main() {

	multiset<int> s;
	// multiset<int, greater<int>> s;

	cout << "size = " << s.size() << endl;
	cout << "empty = " << s.empty() << endl;

	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(1); // ignored, why ? 1 is already is present

	cout << "size : " << s.size() << endl; // 5

	s.erase(5); // if the element you are trying to erase from the set<> exists then it will be deleted, but if the element you are trying to erase is not present in the set<> then nothing will happen

	cout << "size : " << s.size() << endl; // 4

	for (auto it = s.begin(), end = s.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	// set<> doesn't support indexing

	if (s.find(3) != s.end()) {
		cout << "3 is present" << endl;
	} else {
		cout << "3 is absent" << endl;
	}

	if (s.count(3)) {
		cout << "3 is present" << endl;
	} else {
		cout << "3 is absent" << endl;
	}


	s.clear();

	cout << "size : " << s.size() << endl;
	cout << "empty = " << s.empty() << endl;

	return 0;
}