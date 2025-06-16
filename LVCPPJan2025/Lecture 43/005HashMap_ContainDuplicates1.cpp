#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<unordered_set>

using namespace std;

// time : O(nlogn) if you use map<>
// time : on avg. O(n) but worst case O(n^2) if you use unordered_map<>
// space: O(n) due map<> / unordered_map<>

bool isDuplicatePresent(const vector<int>& v) {

	map<int, int> freqMap; // key are elements(int) of v[] and values are their frequencies(int)

	// for (int x : v) {
	// 	freqMap[x]++;
	// }

	// for (int i = 0; i < v.size(); i++) {
	// 	// int x = v[i];
	// 	// freqMap[x]++;

	// 	freqMap[v[i]]++;
	// }

	// for (auto [el, freq] : freqMap) {
	// 	cout << el << "->" << freq << endl;
	// }

	for (int x : v) {
		freqMap[x]++;
		if (freqMap[x] > 1) {
			return true;
		}
	}

	return false;

}

// time : O(nlogn) if you use set<>
// time : on avg. O(n) but worst case O(n^2) if you use unordered_set<>
// space: O(n) due set<> / unordered_set<>

bool isDuplicatePresent2(const vector<int>& v) {

	set<int> s;
	for (int x : v) {
		if (s.find(x) == s.end()) {
			// you are seeing x for the 1st time, track it
			s.insert(x);
		} else {
			// you've seen x previously
			return true; // duplicate found
		}
	}

	// no duplicates found
	return false;

}

int main() {

	vector<int> v = {1, 2, 3, 4, 4};

	isDuplicatePresent(v) ? cout << "duplicate found" << endl :
	                             cout << "duplicate not found" << endl;


	isDuplicatePresent2(v) ? cout << "duplicate found" << endl :
	                              cout << "duplicate not found" << endl;

	return 0;
}