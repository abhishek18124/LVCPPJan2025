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

class Triple {
public :

	int numCameras;
	bool isCovered;
	bool hasCamera;

};

Triple dfs(TreeNode* root) {

	Triple t;

	// base case

	if(root == NULL) {
		t.numCameras = 0;
		t.hasCamera = false;
		t.isCovered = true;
		return t;
	}

	// recursive case

	Triple left = dfs(root->left);
	Triple right= dfs(root->right);

	// decide for the root node

	if(!left.isCovered || !right.isCovered) {
		
		// install camera at the root node
		
		t.numCameras = left.numCameras + right.numCameras + 1;
		t.isCovered = true;
		t.hasCamera = true;
		
	} else {
		
		// don't install camera at root
		
		t.numCameras = left.numCameras + right.numCameras;
		t.isCovered = left.hasCamera || right.hasCamera ? true : false;
		t.hasCamera = false;

	}

	return t;

}

int minCameraCover(TreeNode* root) {

	Triple t = dfs(root);
	if(t.isCovered == false) {
		// install one more camera at the org. root since it is still not cov
		return t.numCameras + 1;
	} else {
		return t.numCameras;
	}

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(0);

	root->left = new TreeNode(0);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(0);

	cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->left->left = new TreeNode(0);
	// root->left->left->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	root = new TreeNode(0);

	root->left = new TreeNode(0);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(0);

	root->right = new TreeNode(0);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(0);

	cout << minCameraCover(root) << endl;

	return 0;
}