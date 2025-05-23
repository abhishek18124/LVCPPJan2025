#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {10, 10, 20, 30, 30, 30, 40, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	// arr[] should sorted to use the following functions

	int key = 50;

	// 1. searching for a key in a sorted sequence in O(logn) using binary_search()

	binary_search(arr, arr + n, key) ? cout << key << " found" << endl : cout << key << " not found" << endl;

	key = 100;

	binary_search(arr, arr + n, key) ? cout << key << " found" << endl : cout << key << " not found" << endl;

	// 2. finding lower bound for a key in a sorted sequence in O(logn) using lower_bound()

	int brr[] = {10, 20, 20, 20, 30, 30, 40};
	int m = sizeof(brr) / sizeof(int);

	key = 20;

	cout << lower_bound(brr, brr + m, key) - brr << endl;

	key = 30;

	cout << lower_bound(brr, brr + m, key) - brr << endl;

	// 3. finding upper bound for a key in a sorted sequence in O(logn) using upper_bound()

	cout << upper_bound(brr, brr + m, key) - brr << endl;

	// 4. counting the occurences of a key in a sorted sequence in O(logn)

	key = 30;

	cout << upper_bound(brr, brr + m, key) - lower_bound(brr, brr + m, key) << endl;

	return 0;
}