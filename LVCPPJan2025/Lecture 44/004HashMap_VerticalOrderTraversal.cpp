/*

	given the pre-order traversal of a binary tree, output its vertical order traversal.

	Example
		Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
		Output: 40
		        20 70
		        10 50
		        30
		        60
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* buildTree() {

	int x;
	cin >> x;

	if (x == -1) {
		TreeNode* root = NULL;
		// root represents an empty tree
		return root;
	}

	TreeNode* root = new TreeNode(x);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

// time : O(nlogn)
// space: O(n) due to map<> + O(h) due to fn call stack ~ O(n)

void dfs(TreeNode* root, int d, map<int, vector<int>>& distMap) {

	// base case

	if (root == NULL) {
		return;
	}

	// recursive case

	distMap[d].push_back(root->val); // logn since we are using map<>
	dfs(root->left, d - 1, distMap);
	dfs(root->right, d + 1, distMap);

}

int main() {

	TreeNode* root = NULL; // init tree is empty
	root = buildTree();

	map<int, vector<int>> distMap;

	dfs(root, 0, distMap);

	for (auto [dist, nodes] : distMap) {
		for (int node : nodes) {
			cout << node << " ";
		}
		cout << endl;
	}

	cout << endl;

	// for (pair<int, vector<int>> p : distMap) {
	// 	int dist = p.first;
	// 	vector<int> nodes = p.second;
	// 	for (int node : nodes) {
	// 		cout << node << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << endl;

	return 0;
}

