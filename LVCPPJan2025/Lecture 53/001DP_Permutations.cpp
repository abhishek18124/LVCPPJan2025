/*

	https://leetcode.com/problems/permutations/

*/

class Solution {
public:

	vector<vector<int>> ans; // to track all the permuations of v[]
	vector<int> perm; // to track a single permuation
	int n; // to track the size of v[]

	void f(const vector<int>& v, int i, int bitmask) {

		// base case

		if (bitmask == (1 << n) - 1) { // i == n
			ans.push_back(perm);
			return;
		}

		// recursive case

		// decide the next element

		for (int j = 0; j < n; j++) {
			// check if the jth option is valid for the ith position

			if ((bitmask >> j) & 1) {
				// jth bit of bitmask is already set
				// which means we cannot use v[j] at
				// the ith position
				continue;
			}

			// jth bit of bitmask is not set
			// therefore you can use v[j] at
			// the ith position

			perm.push_back(v[j]);
			f(v, i + 1, bitmask | (1 << j));
			perm.pop_back(); // backtracking

		}

	}

	vector<vector<int>> permute(vector<int>& v) {
		this->n = v.size();
		f(v, 0, 0);
		return ans;
	}
};
