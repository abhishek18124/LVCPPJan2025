#include<iostream>
#include<vector>

using namespace std;

class TreeNode {

public :

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}

};

int countPaths(TreeNode* root, int targetSum) {

	// base case

	if (root == NULL) {
		return 0;
	}

	// recursive case

	// f(root, targetSum) : count no. of paths in the given tree that start at the root
	// whose sum is equal to targetSum

	int cnt = 0;

	if (root->val == targetSum) cnt++;
	cnt += countPaths(root->left, targetSum - root->val);
	cnt += countPaths(root->right, targetSum - root->val);

	return cnt;

}


int main() {

	TreeNode* root = NULL;

	root = new TreeNode(2);

	root->left = new TreeNode(7);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(1);
	root->left->left->right = new TreeNode(8);
	root->left->right = new TreeNode(3);

	root->right = new TreeNode(6);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	int targetSum = 12;

	cout << countPaths(root, targetSum) << endl;

	// TreeNode* root = NULL;

	// root = new TreeNode(4);

	// root->left = new TreeNode(7);
	// root->left->left = new TreeNode(3);
	// root->left->left->left = new TreeNode(1);
	// root->left->left->right = new TreeNode(8);
	// root->left->right = new TreeNode(3);

	// root->right = new TreeNode(6);
	// root->right->left = new TreeNode(4);
	// root->right->right = new TreeNode(5);

	// int targetSum = 4;

	// cout << countPaths(root, targetSum) << endl;

	return 0;
}