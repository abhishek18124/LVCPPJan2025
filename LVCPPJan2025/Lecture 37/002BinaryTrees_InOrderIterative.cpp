// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
	// space: O(h) size of stack depends on the height of the tree

	vector<int> inorderTraversal(TreeNode* root) {

		vector<int> ans;
		TreeNode* cur = root;
		stack<TreeNode*> s;

		while (!s.empty() || cur != NULL) {

			if (cur != NULL) {

				s.push(cur);
				cur = cur->left;

			} else {

				cur = s.top(); s.pop();
				ans.push_back(cur->val);
				cur = cur->right;

			}

		}

		return ans;


	}
};