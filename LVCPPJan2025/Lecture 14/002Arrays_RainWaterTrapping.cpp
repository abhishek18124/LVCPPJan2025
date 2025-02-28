#include<iostream>
#include<vector>

using namespace std;

// time : O(n^2)
// space: O(1)

int trap(const vector<int>& height) {

	int n = height.size();
	int ans = 0; // to track total water trapped b/w the buidlings

	for (int i = 0; i < n; i++) {

		// find out the water trapped on top of the ith building

		// li = max(height[0...i])

		int li = height[i];
		for (int j = i - 1; j >= 0; j--) {
			li = max(li, height[j]);
		}

		// ri = max(height[i...n-1])

		int ri = height[i];
		for (int j = i + 1; j <= n - 1; j++) {
			ri = max(ri, height[j]);
		}

		int wi = min(li, ri) - height[i];
		ans += wi;

	}

	return ans;

}

int main() {

	vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	cout << trap(height) << endl;

	return 0;
}