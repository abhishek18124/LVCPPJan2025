/*

Given an array of non-negative integers, find the maximum subarray XOR.

Example:
	Input : x[] = {25, 10, 2, 8, 5, 3}
	Output:

*/

#include<iostream>
#include<climits>
#include<vector>

using namespace std;

class node {
public:

	node* left;  // indicates if node has a child that represents bit 0
	node* right; // indicates if node has a child that represents bit 1

	node() {
		this->left = NULL;
		this->right = NULL;
	}
};

class trie {

	node* root;

public:

	trie() {
		root = new node();
	}

	void insert(int n) {
		node* temp = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (1 << i)&n;
			if (!bit) {
				// ith bit of n is 0, check if temp node has a left child or not
				if (!temp->left) {
					node* n = new node();
					temp->left = n;
				}
				temp = temp->left;
			} else {
				// ith bit of n is 1, check if temp node has a right child or not
				if (!temp->right) {
					node* n = new node();
					temp->right = n;
				}
				temp = temp->right;
			}
		}
	}

	int helper(int n) {
		int ans = 0;
		node* cur = root;
		for (int k = 31; k >= 0; k--) {
			int kthBit = (n >> k) & 1;
			if (kthBit == 0) {
				if (cur->right != NULL) {
					// kthBit of ans can be set
					ans = ans | (1 << k); // ans = ans + (1<<k)
					cur = cur->right;
				} else {
					// kthBit of ans cannot be set
					cur = cur->left;
				}
			} else {
				// kthBit == 1
				if (cur->left != NULL) {
					// kthBit of ans can be set
					ans = ans | (1 << k);
					cur = cur->left;
				} else {
					// kthBit of ans cannot be set
					cur = cur->right;
				}
			}
		}

		return ans;
	}

	// time : n.32 ~ O(n)

	int maximumPairXOR(vector<int>& x, int n) {
		int maxSoFar = 0;
		for (int i = 0; i < n; i++) {
			maxSoFar = max(maxSoFar, helper(x[i]));
		}
		return maxSoFar;
	}
};


int main() {

	int arr[] = {25, 10, 2, 8, 5, 3};
	int n = sizeof(arr) / sizeof(int);

	// brute-force approach - time : O(n^3) space : O(1)

	int maxSoFar = 0; // to track the maximum subarray XOR

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// compute the xor of arr[i...j]
			int XOR = 0;
			for (int k = i; k <= j; k++) {
				XOR ^= arr[k];
			}
			maxSoFar = max(maxSoFar, XOR);
		}
	}

	cout << maxSoFar << endl;

	// using pxor[] - time : n + n^2 ~ O(n^2) space : O(n) due pxor[]

	int maxSoFar2 = 0;

	vector<int> pxor(n + 1);
	pxor[0] = 0;
	for (int i = 1; i <= n; i++) {
		pxor[i] = pxor[i - 1] ^ arr[i - 1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// compute the xor of arr[i...j] using pxor[]
			int XOR = pxor[j + 1] ^ pxor[i];
			maxSoFar2 = max(maxSoFar2, XOR);
		}
	}

	cout << maxSoFar2 << endl;

	// 3rd approach - using trie - time : O(n)

	trie t;

	for (int i = 0; i <= n; i++) {
		t.insert(pxor[i]);
	}

	cout << t.maximumPairXOR(pxor, n + 1) << endl;


	return 0;
}