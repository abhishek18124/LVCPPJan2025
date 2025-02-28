#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

	int n = nums.size();
	vector<vector<int>> ans;

	for (int i = 0; i <= n - 3; i++) {
		for (int j = i + 1; j <= n - 2; j++) {
			for (int k = j + 1; k <= n - 1; k++) {
				int tripletSum = nums[i] + nums[j] + nums[k];
				if (tripletSum == 0) { // found a valid triplet
					ans.push_back({nums[i], nums[j], nums[k]});
				}
			}
		}
	}

	return ans;

}

int main() {

	vector<int> nums = { -1, 0, 1, 2, -1, -4};

	return 0;

}