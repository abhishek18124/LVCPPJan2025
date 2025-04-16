#include<iostream>
#include<vector>

using namespace std;

void generatePermutations(int t, const vector<int>& c, vector<int>& perm) {

	// base case

	if (t == 0) {
		// you've built a permuation that sums upto t
		for (auto x : perm) {
			cout << x << " ";
		}
		cout << endl;
		return;
	}

	// recursion case

	// generate permutations of 'c' that sums up to 't' or choose candidates that sum up to 't'

	// decide the next candidate

	for (auto x : c) {

		if (x <= t) {

			// you can choose x as the next candidate to be in the permuation you are building

			// perm.push_back(x);
			// t = t - x;
			// generatePermutations(t, c, perm);
			// t = t + x; // backtracking
			// perm.pop_back(); // backtracking

			perm.push_back(x);
			generatePermutations(t - x, c, perm);
			perm.pop_back(); // backtracking

		}

	}

}

int main() {

	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> perm; // to track the permutation that sums up to 't'

	generatePermutations(t, c, perm);

	return 0;
}