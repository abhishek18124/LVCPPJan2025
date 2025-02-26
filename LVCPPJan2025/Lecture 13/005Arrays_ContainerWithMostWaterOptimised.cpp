#include<iostream>
#include<vector>

using namespace std;

// time : O(n)

int maxArea(vector<int>& height) {

	int maxSoFar = 0;
	int n = height.size();

	int i = 0;
	int j = n - 1;

	while (i < j) {

		// find the area of the container formed using the ith and jth line

		int w = j - i;
		int h =  min(height[i], height[j]);
		int a = w * h;

		maxSoFar = max(maxSoFar, a);

		if (height[i] < height[j]) {
			i++;
		} else {
			j--;
		}

	}

	return maxSoFar;

}

int main() {

	vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

	cout << maxArea(height) << endl;

	return 0;

}