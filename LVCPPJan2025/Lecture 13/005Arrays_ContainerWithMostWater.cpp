#include<iostream>
#include<vector>

using namespace std;

// time : O(n^2)

int maxArea(vector<int>& height) {

	int maxSofar = 0;
	int n = height.size();

	for (int i = 0; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			// find the area of the container formed using the ith and jth line
			int w = j - i;
			int h = min(height[i], height[j]);
			int a = w * h;
			maxSofar = max(maxSofar, a);
		}
	}

	return maxSofar;

}

int main() {

	vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

	cout << maxArea(height) << endl;

	return 0;

}