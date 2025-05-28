// https://leetcode.com/problems/binary-tree-inorder-traversal/

// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
	// space : O(1)

	vector<int> inorderTraversal(TreeNode* root) {

		vector<int> ans;
		TreeNode* cur = root;

		while (cur != NULL) {

			if (cur->left == NULL) {
				ans.push_back(cur->val);
				cur = cur->right;
			} else {

				TreeNode* temp = cur->left;
				while (temp->right != NULL and temp->right != cur) {
					temp = temp->right;
				}

				if (temp->right == NULL) {
					// add a thread
					temp->right = cur;
					cur = cur->left;
				} else {
					// remove thread
					temp->right = NULL;
					ans.push_back(cur->val);
					cur = cur->right;
				}

			}

		}

		return ans;

	}
};