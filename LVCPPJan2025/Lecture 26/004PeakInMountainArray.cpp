#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {

		int n = arr.size();

		int s = 0;
		int e = n - 1;

		while (s < e) {

			int m1 = s + (e - s) / 3;
			int m2 = e - (e - s) / 3;

			if (arr[m1] > arr[m2]) {

				// go to the left of m2 to find the peak

				e = m2 - 1;

			} else {

				// arr[m1] < arr[m2]

				// go the right of m1 to find the peak

				s = m1 + 1;

			}

		}

		return s; // or s

	}
};

int main() {

	Solution s;
	vector<int> arr = {0, 1, 3, 10, 3, 1, 0};
	cout << s.peakIndexInMountainArray(arr) << endl;

	return 0;
}