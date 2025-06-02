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

	int countPaths(TreeNode* root, long long targetSum) {

		// base case

		if (root == NULL) {
			return 0;
		}

		// recursive case

		// f(root, targetSum) : count no. of paths in the given tree that start at the root
		// whose sum is equal to targetSum

		int cnt = 0;

		if (root->val == targetSum) cnt++;
		cnt += countPaths(root->left, targetSum - root->val);
		cnt += countPaths(root->right, targetSum - root->val);

		return cnt;

	}

	// time : O(n^2)

	int dfs(TreeNode* root, int targetSum) {

		// base case

		if (root == NULL) {
			return 0;
		}

		// recursive case

		// f(root, targetSum) : count no. of paths in the given tree
		// whose sum is equal to targetSum

		int cnt = 0;

		// 1. count no. of paths in the given tree that start at root
		// whose sum is equal to targetSum

		cnt += countPaths(root, targetSum);

		// 2. count no. of paths in the given tree that donot start at
		// root whose sum is equal to targetSum

		// 2.1 count no. of paths in the leftSubtree whose sum is equal
		// to targetSum

		cnt += dfs(root->left, targetSum);

		// 2.2. count no. of paths in the rightSubtree whose sum is equal
		// to targetSum

		cnt += dfs(root->right, targetSum);

		return cnt;

	}

	int pathSum(TreeNode* root, int targetSum) {
		return dfs(root, targetSum);
	}
};