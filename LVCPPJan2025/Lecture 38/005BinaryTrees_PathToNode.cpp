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

vector<int> path;
bool flag = false; // assume, we have not yet found the path to the target node

void dfs(TreeNode* root, int target) {

	// base case

	if (root == NULL) {
		return;
	}

	if (root->val == target) {
		// you've found the path to the target node
		flag = true;
		path.push_back(root->val);
		for (int x : path) {
			cout << x << " ";
		}
		path.pop_back(); // optional
		cout << endl;
	}

	// recursive case

	path.push_back(root->val);
	dfs(root->left, target);
	// if (flag) return;
	dfs(root->right, target);
	path.pop_back();

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(2);

	root->left = new TreeNode(7);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(1);
	root->left->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(9);
	root->left->right = new TreeNode(8);

	root->right = new TreeNode(6);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(5);

	int target = 3;

	dfs(root, target);

	return 0;
}