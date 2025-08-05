/**
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 *
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

    vector<int> bfs(int src, map<int, vector<int>> adj, int k) {

        map<int, int> distMap;
        distMap[src] = 0;

        queue<int> q;
        q.push(src);

        set<int> vis;
        vis.insert(src);

        while (!q.empty()) {

            int cur = q.front();
            q.pop();

            for (int ngb : adj[cur]) {
                if (vis.find(ngb) == vis.end()) {
                    // ngb is not yet visited
                    vis.insert(ngb);
                    q.push(ngb);
                    distMap[ngb] = distMap[cur] + 1;
                }
            }

        }

        vector<int> ans;

        for (auto [node, dis] : distMap) {
            if (dis == k) {
                ans.push_back(node);
            }
        }

        return ans;

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        queue<TreeNode*> q;
        q.push(root);

        map<int, vector<int>> adj;

        while (!q.empty()) {

            TreeNode* front = q.front();
            q.pop();

            if (front->left != NULL) {
                q.push(front->left);
                adj[front->val].push_back(front->left->val);
                adj[front->left->val].push_back(front->val);
            }

            if (front->right != NULL) {
                q.push(front->right);
                adj[front->val].push_back(front->right->val);
                adj[front->right->val].push_back(front->val);
            }

        }

        return bfs(target->val, adj, k);

    }
};