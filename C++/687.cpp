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
    int dfs(TreeNode* root, int& ans){
        int l = 0, r = 0;
        if(root->left){
            if(root->val == root->left->val)
                l = dfs(root->left, ans);
            else
                dfs(root->left, ans);
        }
        if(root->right){
            if(root->val == root->right->val)
                r = dfs(root->right, ans);
            else
                dfs(root->right, ans);
        }
        ans = max(ans, l + r + 1);
        return 1 + max(l, r);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        dfs(root, ans);
        return ans - 1; // ans stands for the number of nodes in the path, the we should minus 1 to get length of the path
    }
};