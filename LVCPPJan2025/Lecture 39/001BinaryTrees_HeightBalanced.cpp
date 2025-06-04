
/*
given the pre-order traversal of a binary tree, check if it is height balanced or not

Example
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: true

	Input : 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
	Output: true

	Input : 10 20 30 -1 -1 -1 -1
	Output: false

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

bool checkHeightBalanced(TreeNode* root) {

	// base case

	if(root == NULL) {
		return true;
	}

	// recursive case

	// f(root) : check if the given tree is height balanced or not

	// 1. ask your friend to check if the leftSubtree is heightBalanced

	bool leftIsBal = checkHeightBalanced(root->left);

	// 2. ask your friend to check if the rightSubtree is heightBalanced

	bool rightIsBal = checkHeightBalanced(root->right);

	// 3. check if the heightBalance prop. works at the root node

	bool rootIsBal = abs(computeHeight(root->left) - computeHeight(root->right)) <= 1 ? true : false;

	return leftIsBal and rightIsBal and rootIsBal;

}

class Pair {

public:

	bool isBal;
	int hgt;

};

// time : O(n)

Pair checkHeightBalancedOptimised(TreeNode* root) {

	Pair p;

	// base case

	if(root == NULL) {
		p.isBal = true;
		p.hgt = -1;
		return p;
	}

	// recursive case

	Pair left = checkHeightBalancedOptimised(root->left);
	Pair right= checkHeightBalancedOptimised(root->right);

	bool rootIsBal = abs(left.hgt - right.hgt) <= 1 ? true : false;

	p.hgt = 1 + max(left.hgt, right.hgt);
	p.isBal = left.isBal and right.isBal and rootIsBal;

	return p;

}

pair<int, bool> checkHeightBalancedOptimised2(TreeNode* root) {

	pair<int, bool> p;

	// base case

	if(root == NULL) {
		p.first = -1;
		p.second = true;
		return p;
	}

	// recursive case

	pair<int, bool> left = checkHeightBalancedOptimised2(root->left);
	pair<int, bool> right= checkHeightBalancedOptimised2(root->right);

	bool rootIsBal = abs(left.first - right.first) <= 1 ? true : false;

	p.first = 1 + max(left.first, right.first);
	p.second = left.second and right.second and rootIsBal;

	return p;

}

int main() {

	TreeNode* root = buildTree();

	checkHeightBalanced(root) ? cout << "height-balanced!" << endl : cout << "not height-balanced" << endl;

	Pair p = checkHeightBalancedOptimised(root);

	p.isBal ? cout << "height-balanced!" << endl : cout << "not height-balanced!" << endl;

	pair<int, bool> p2 = checkHeightBalancedOptimised2(root);

	p2.second ? cout << "height-balanced!" << endl : cout << "not height-balanced!" << endl;

	return 0;
}