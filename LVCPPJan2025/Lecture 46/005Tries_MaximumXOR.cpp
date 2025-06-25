/*

Given an array of non-negative integers of size n, find the maximum possible XOR between
any two numbers present in the array.

Example:
	Input : x[] = {25, 10, 2, 8, 5, 3}
	Output: 28
	Explaination: The maximum result is 5 ^ 25 = 28

	Input: x[] = {1, 2, 3, 4, 5, 6, 7}
	Output: 7
	Explaination: The maximum result is 1 ^ 6 = 7

*/

#include<iostream>
#include<climits>

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

		cout << n << "^" << (n ^ ans) << " = " << ans << endl;

		return ans;
	}

	// time : n.32 ~ O(n)

	int maximumPairXOR(int x[], int n) {
		int maxSoFar = 0;
		for (int i = 0; i < n; i++) {
			maxSoFar = max(maxSoFar, helper(x[i]));
		}
		return maxSoFar;
	}
};

int main() {

	int x[] = {2, 4, 5, 8, 10};
	int n = sizeof(x) / sizeof(int);

	// appr1 - brute force O(n^2)

	int maxSofar = 0; // to track the maximum XOR pair

	for (int i = 0; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			cout << x[i] << "^" << x[j] << " = " << (x[i] ^ x[j]) << endl;
			maxSofar = max(maxSofar, x[i] ^ x[j]);
		}
		cout << endl;
	}

	cout << "ans = " << maxSofar << endl;

	// appr2 - using trie

	// time for building trie = n.32 ~ O(n)

	trie t;

	for (int i = 0; i < n; i++) {
		t.insert(x[i]);
	}

	cout << t.maximumPairXOR(x, n) << endl;

	return 0;
}