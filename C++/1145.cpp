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
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        return dfs(root->left) + dfs(root->right) + 1;
    }
    TreeNode* find_red(TreeNode* root, int x){
        if(!root)
            return NULL;
        if(root->val == x)
            return root;
        TreeNode *l = find_red(root->left, x);
        TreeNode *r = find_red(root->right, x);
        return l ? l : r;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        // using DFS
        TreeNode *red = find_red(root, x);
        int left_cnt = dfs(red->left), right_cnt = dfs(red->right);
        return (left_cnt > n / 2 || right_cnt > n / 2 || (n - left_cnt - right_cnt - 1) > n / 2);
    }
};