/*
	https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:

	// time : O(nlogn) since we are using a map<>
	// time : on avg. O(n) but worst case O(n^2) if we are using a unordered_map<>
	// space: O(n) due to map<> or unordered_map<>

	int longestConsecutive(vector<int>& nums) {

		map<int, bool> startMap;

		for (int num : nums) {

			if (startMap.find(num - 1) == startMap.end()) {
				startMap[num] = true;
			} else {
				startMap[num] = false;
			}

			if (startMap.find(num + 1) != startMap.end()) {
				startMap[num + 1] = false;
			}

		}

		int maxSofar = 0;

		for (pair<int, bool> p : startMap) {
			int el = p.first;
			bool canStart = p.second;
			if (canStart) {
				int cnt = 0;
				while (startMap.find(el) != startMap.end()) {
					cnt++;
					el++;
				}
				maxSofar = max(maxSofar, cnt);
			}
		}

		return maxSofar;

	}
};

int main() {

	Solution s;

	vector<int> nums = {0, 1, 4, 5, 6, 11, 12, 13, 14};

	cout << s.longestConsecutive(nums) << endl;

}
