#include<iostream>

using namespace std;

int binarySearch(int arr[], int n, int t) {

	int s = 0;
	int e = n - 1;

	while (s <= e) {

		// int m = (s + e) / 2;
		int m = s + (e - s) / 2;
		if (arr[m] == t) {
			// you've found the target at index m
			return m;
		} else if (t > arr[m]) {
			// search for the target to the right
			// of the midPoint i.e. search space
			// reduces from [s, e] to [m+1, e]
			s = m + 1;
		} else {
			// t < arr[m]
			// search for the target to the left
			//  of the midPoint i.e. search space
			// reduces from [s, e] to [s, m-1]
			e = m - 1;
		}

	}

	// s > e i.e. target was not found
	return -1;

}

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int t = 20;

	cout << binarySearch(arr, n, t) << endl;

	return 0;
}