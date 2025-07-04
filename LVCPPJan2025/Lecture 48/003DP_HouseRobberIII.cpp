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

    int f(TreeNode* root, map<TreeNode*, int>& dp) {

        // lookup

        if (dp.find(root) != dp.end()) {
            return dp[root];
        }

        // base case

        if (root == NULL) {
            return dp[root] = 0;
        }

        // recursive case

        // f(root) = find the maximum profit you can make from the given tree
        // which is rooted at the 'root' node w/o alerting the police

        // decide for the root node

        // option 1: rob the root node

        int robOption = root->val;

        if (root->left != NULL) {
            robOption += f(root->left->left, dp);
            robOption += f(root->left->right, dp);
        }

        if (root->right) {
            robOption += f(root->right->left, dp);
            robOption += f(root->right->right, dp);
        }


        // option 2: don't rob the root node

        int donotRobOption = f(root->left, dp) + f(root->right, dp);

        return dp[root] = max(robOption, donotRobOption);

    }

    int rob(TreeNode* root) {
        map<TreeNode* , int> dp;
        return f(root, dp);
    }
};