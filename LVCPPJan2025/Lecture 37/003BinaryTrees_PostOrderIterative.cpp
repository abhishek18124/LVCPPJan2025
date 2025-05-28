// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
	// space: O(n)

	vector<int> postorderTraversal(TreeNode* root) {

		vector<int> ans;
		stack<pair<TreeNode*, int>> s;
		TreeNode* cur = root;

		while (!s.empty() || cur != NULL) {

			if (cur != NULL) {
				s.push({cur, 1}); // s.push(make_pair(cur, 1));
				cur = cur->left;
			} else {
				auto& [node, status] = s.top();
				if (status == 1) {
					status = 2; // don't forget status is ref to s.top().second
					cur = node->right;
				} else {
					// status == 2
					ans.push_back(node->val);
					s.pop();
				}

			}

		}

		return ans;

	}
};