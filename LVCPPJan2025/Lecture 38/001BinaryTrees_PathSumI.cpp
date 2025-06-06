/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

	// time : O(n)
	// space: O(h) due to fn call stack, here h is the height of the tree

	bool dfs(TreeNode* root, int targetSum) {

		// base case

		if (root == NULL) {
			return false;
		}

		if (root->left == NULL and root->right == NULL) { // you've reached a leaf node
			if (root->val == targetSum) {
				// you've built a valid path
				return true;
			}
			// the root to leaf path you've built is not valid
			return false;
		}

		// recursive case

		// f(root, targetSum) : check if there exists a root to leaf path
		// in the given tree whose sum is equal to targetSum

		// 1. ask your friend to check if there exists a root to leaf path
		// in the leftSubtree whose sum is equal to targetSum - root->val

		// 2. ask your friend to check if there exists a root to leaf path
		// in the rightSubtree whose sum is equal to targetSum - root->val

		return dfs(root->left, targetSum - root->val) or dfs(root->right, targetSum - root->val);

	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		return dfs(root, targetSum);
	}
};