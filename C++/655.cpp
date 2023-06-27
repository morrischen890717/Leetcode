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
    void getHeight(TreeNode *root, int cur, int &height){
        if(!root){
            height = max(height, cur);
            return;
        }
        getHeight(root->left, cur + 1, height);
        getHeight(root->right, cur + 1, height);
        return;
    }
    void dfs(TreeNode *root, vector<vector<string>> &ans, int l, int n, int h){
        if(!root)
            return;
        int pos = l + (n - 1) / 2;
        ans[h][pos] = to_string(root->val);
        dfs(root->left, ans, l, (n - 1) / 2, h + 1);
        dfs(root->right, ans, pos + 1, (n - 1) / 2, h + 1);
        return;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = 0;
        getHeight(root, -1, h);
        vector<vector<string>> ans(h + 1, vector<string> (pow(2, h + 1) - 1, ""));
        int n = pow(2, h + 1) - 1;
        dfs(root, ans, 0, n, 0);
        return ans;
    }
};