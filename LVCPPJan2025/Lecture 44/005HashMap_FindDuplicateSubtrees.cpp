/*
	https://leetcode.com/problems/find-duplicate-subtrees/
*/

class Solution {
public:

	map<string, TreeNode*> treeMap;
	set<TreeNode*> ans;

	string dfs(TreeNode* root) {

		// base case

		if (root == NULL) {
			return "";
		}

		// recursive case

		string leftRepr  = dfs(root->left);
		string rightRepr = dfs(root->right);

		string treeRepr = to_string(root->val) + "/" + leftRepr + "/" + rightRepr;

		if (treeMap.find(treeRepr) != treeMap.end()) {
			// we've seen the subtree rooted at root
			// previously i.e. we've found a duplicate
			// subtree
			ans.insert(treeMap[treeRepr]);
		} else {
			treeMap[treeRepr] = root;
		}

		return treeRepr;

	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		dfs(root);

		// vector<TreeNode*> v(ans.begin(), ans.end());
		// return v;

		// vector<TreeNode*> v;
		// for (auto addr : s) {
		// 	v.push_back(addr);
		// }

		return vector<TreeNode*>(ans.begin(), ans.end());

	}
};