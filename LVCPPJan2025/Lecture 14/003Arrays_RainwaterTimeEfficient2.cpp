#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// time : 3n.const ~ O(n)
// space: n due to r[] ~ O(n)

int trap(vector<int>& height) {

	int n = height.size();

	// precompute r[]

	vector<int> r(n);
	r[n - 1] = height[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i + 1], height[i]);
	}

	int ans = 0; // to track total water trapped b/w the buidlings
	int li = INT_MIN;

	for (int i = 0; i < n; i++) {

		// find out the water trapped on top of the ith building

		li = max(li, height[i]); // li represents max(height[0...i])
		int wi = min(li, r[i]) - height[i];
		ans += wi;

	}

	return ans;

}

int main() {

	vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	cout << trap(height) << endl;

	return 0;
}