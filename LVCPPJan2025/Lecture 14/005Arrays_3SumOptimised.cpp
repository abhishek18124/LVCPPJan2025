#include<iostream>
#include<vector>

using namespace std;

// time : nlogn + n^2 ~ O(n^2)

vector<vector<int>> threeSum(vector<int>& nums) {

	int n = nums.size();

	sort(nums.begin(), nums.end());

	vector<vector<int>> ans;

	// iterate over all the possible values of 1st element

	for (int i = 0; i <= n - 3; i++) {

		// can you fix nums[i] as the 1st element

		if (nums[i] > 0) {
			break;
		}

		if (i > 0 and nums[i] == nums[i - 1]) {
			continue;
		}

		// fix nums[i] as the 1st element of the triplet

		// now, search for the pair nums[j], nums[k] in [i+1...n-1]

		// such that nums[j] + nums[k] = -num[i]

		int t = -nums[i];
		int j = i + 1;
		int k = n - 1;

		while (j < k) {
			int pairSum = nums[j] + nums[k];
			if (pairSum == t) {
				// you've found a valid triplet
				ans.push_back({nums[i], nums[j], nums[k]});
				j++;
				k--;

				while (j < k and nums[j] == nums[j - 1]) j++;
				while (j < k and nums[k] == nums[k + 1]) k--;

			} else if (pairSum > t) {
				k--;
			} else {
				// pairSum < t
				j++;
			}
		}

	}

	return ans;

}

int main() {

	vector<int> nums = { -1, 0, 1, 2, -1, -4};

	return 0;

}