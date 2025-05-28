// https://leetcode.com/problems/flip-equivalent-binary-trees/

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

	bool dfs(TreeNode* root1, TreeNode* root2) {

		// base case

		if (root1 == NULL and root2 == NULL) {
			return true;
		}

		if (root1 == NULL and root2 != NULL) {
			return false;
		}

		if (root1 != NULL and root2 == NULL) {
			return false;
		}

		// recursive case

		// root1 != NULL and root2 != NULL

		// f(root1, root2) : check if root1 and root2 are flip equivalent or not

		if (root1->val != root2->val) {
			return false;
		}

		// root1->val matches root2->val

		// decide for the root1

		// option 1 : do a flip
		swap(root1->left, root1->right);
		if (dfs(root1->left, root2->left) and dfs(root1->right, root2->right)) {
			// tree1 and tree2 are flip equivalent
			return true;
		}
		swap(root1->left, root1->right); // backtracking


		// option 2: don't do flip
		if (dfs(root1->left, root2->left) and dfs(root1->right, root2->right)) {
			// tree1 and tree2 are flip equivalent
			return true;
		}

		// tree1 and tree2 are not flip equivalent
		return false;

	}

	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		return dfs(root1, root2);
	}
};