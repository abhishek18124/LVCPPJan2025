// https://leetcode.com/problems/find-the-duplicate-number/description/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {

		int slow = nums[0];
		int fast = nums[0];

		while (true) {
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast) {
				break;
			}
		}

		slow = nums[0];
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}

		return slow; // return fast; // slow and fast are at the start of the cycle i.e. at the duplicate number


	}
};

int main() {

	Solution s;

	vector<int> nums = {2, 5, 4, 5, 1, 6, 3};

	cout << s.findDuplicate(nums) << endl;

	return 0;

}