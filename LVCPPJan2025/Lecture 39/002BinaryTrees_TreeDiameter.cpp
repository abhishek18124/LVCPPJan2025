/*

given the pre-order traversal of a binary tree, design a recursive algorithm
to compute its diameter

	  diameter of a binary tree is the length of the longest path between any
	  two TreeNodes in the binary tree.

Example : Input  : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 5

          Input  : 10 20 30 50 70 -1 -1 -1 -1 40 -1 60 -1 80 -1 -1 90 -1 -1
          Output : 6

          Input  : 10 20 -1 -1 30 40 60 80 -1 -1 -1 -1 50 -1 70 -1 90 -1 -1
          Output : 6

*/

#include<iostream>
#include<cmath>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};


TreeNode* buildTree() {

	int val;
	cin >> val;

	// base case

	if (val == -1) {
		// construct an empty tree and return pointer to its root TreeNode
		return NULL;
	}

	// recursive case

	// 1. construct the root val using the first value of the given preOrder traversal

	TreeNode* root = new TreeNode(val);

	// 2. ask your friend to construct the leftSubtree from the preOrder traversal of the leftSubtree

	root->left = buildTree();

	// 3. ask your friend to construct the rightSubtree from the preOrder traversal of the rightSubtree

	root->right = buildTree();

	return root;

}

int computeHeight(TreeNode* root) {

	// base case

	if (!root) { // root == NULL
		// height of empty tree is -1
		return -1;
	}

	// recursive case

	// 1. recursively, compute the height of the leftSubtree
	int x = computeHeight(root->left);

	// 2. recursively, compute the height of the rightSubtree
	int y = computeHeight(root->right);

	return 1 + max(x, y);

}

// time : O(n^2)

int computeDiameter(TreeNode* root) {

	// base case

	if(root == NULL) {
		return 0;
	}

	// recursive case

	// f(root) : find the diameter of the given tree i.e. the length of the longest path 
	// b/w any two nodes in the given tree

	// 1. ask your friend to find the diameter of the LST

	int leftDia = computeDiameter(root->left);

	// 2. ask your friend to find the diameter of the RST

	int rightDia = computeDiameter(root->right);

	// 3. find the length of the longest path that goes through root

	int lenOfLongestPathThroughtRoot = computeHeight(root->left) + computeHeight(root->right) + 2;

	return max(leftDia, max(rightDia, lenOfLongestPathThroughtRoot));

	// return max({leftDia, rightDia, lenOfLongestPathThroughtRoot});	

}

class Pair {
public:
	int hgt;
	int dia;
};

// time : O(n)

Pair computeDiameterOptimised(TreeNode* root) {

	Pair p;

	// base case

	if(root == NULL) {
		p.hgt = -1;
		p.dia = 0;
		return p;
	}

	// recursive case

	Pair left = computeDiameterOptimised(root->left);
	Pair right= computeDiameterOptimised(root->right);

	int lenOfLongestPathThroughtRoot = left.hgt + right.hgt + 2;

	p.hgt = 1 + max(left.hgt, right.hgt);
	p.dia = max(left.dia, max(right.dia, lenOfLongestPathThroughtRoot));

	return p;

}

int main() {

	TreeNode* root = buildTree();

	cout << computeDiameter(root) << endl;

	Pair p = computeDiameterOptimised(root);

	cout << p.dia << endl;

	return 0;
}