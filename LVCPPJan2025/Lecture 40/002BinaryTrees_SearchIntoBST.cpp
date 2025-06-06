/*

	Given a BST and a key, design an algorithm to search for the key in the BST.

	Output "true" is key is found otherwise output "false".

*/

#include<iostream>

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

// time : O(h)

bool search(TreeNode* root, int key) {

	// base case

	if (root == NULL) {
		return false;
	}

	// recursive case

	if (root->val == key) {
		return true;
	} else if (key < root->val) {
		// ask your friend to search for the key in the LST
		return search(root->left, key);
	} else {
		// key > root->val
		// ask your friend to search for the key in the RST
		return search(root->right, key);
	}

}


bool search2(TreeNode* root, int key) {

	// base case

	if (root == NULL) {
		return false;
	}

	if (root->val == key) {
		return true;
	}

	// recursive case

	if (key < root->val) {
		// ask your friend to search for the key in the LST
		return search(root->left, key);
	} else {
		// key > root->val
		// ask your friend to search for the key in the RST
		return search(root->right, key);
	}

}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	search(root, 6) ? cout << "true" << endl : cout << "false" << endl;
	search2(root, 6) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}


