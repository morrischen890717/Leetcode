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
        return root->val + dfs(root->left) + dfs(root->right);
    }
    int solve(TreeNode* root, int total, long long& ans){
        if(!root)
            return 0;
        int sub_val = root->val + solve(root->left, total, ans) + solve(root->right, total, ans);
        ans = max(ans, (long long)sub_val * (total - sub_val));
        return sub_val;
    }
    int maxProduct(TreeNode* root) {
        // using DFS
        // time complexity: O(N)
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int total = dfs(root);
        solve(root, total, ans);
        return ans % MOD;
    }
};