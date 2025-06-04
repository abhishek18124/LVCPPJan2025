
// https://leetcode.com/problems/diameter-of-binary-tree/

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

    int ans = 0; // to track diameter of the tree

    int dfs(TreeNode* root) {

        // base case

        if(root == NULL) {
            return -1;
        }

        // recursive case

        int leftHgt = dfs(root->left);
        int rightHgt = dfs(root->right);

        int lenOfLongestPathThroughRoot = leftHgt + rightHgt + 2;
        ans = max(ans, lenOfLongestPathThroughRoot);

        return 1 + max(leftHgt, rightHgt);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};