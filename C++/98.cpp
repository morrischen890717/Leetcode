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
    bool dfs(TreeNode* node, long long& prev){
        if(!node)
            return true;
        return dfs(node->left, prev) && node->val > prev && dfs(node->right, prev = node->val);
    }
    bool isValidBST(TreeNode* root) {
        // just using DFS and set prev to the value of the previous node which was visited, if the value of current node <= prev then return false
        long long prev = LLONG_MIN;
        return dfs(root, prev);
    }
};