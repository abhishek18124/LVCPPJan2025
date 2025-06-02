/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	// time : O(n)
	// space: O(h) due to fn call stack

	TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {

		// base case

		if (root == NULL) {
			return NULL;
		}

		if (root == p || root == q) {
			return root;
		}

		// recursive case

		// dfs(root, p, q) : find the lca of nodes p and q in the given tree (root)

		TreeNode* left = dfs(root->left, p, q);
		TreeNode* right = dfs(root->right, p, q);

		if (left != NULL and right != NULL) {
			return root;
		} else if (left != NULL) {
			return left;
		} else if (right != NULL) {
			return right;
		} else {
			return NULL;
		}

	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		return dfs(root, p, q);
	}
};