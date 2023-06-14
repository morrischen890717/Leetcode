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
    void dfs(TreeNode* node, int& prev, int& dis){
        if(!node)
            return;
        dfs(node->left, prev, dis);
        dis = min(dis, node->val - prev);
        dfs(node->right, prev = node->val, dis);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        // using DFS with inorder traversal
        int dis = INT_MAX;
        int prev = -1e5;
        dfs(root, prev, dis);
        return dis;
    }
};