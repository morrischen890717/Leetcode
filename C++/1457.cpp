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
    void dfs(TreeNode* root, int& cur, int& ans){
        if(!root)
            return;
        cur ^= (1 << (root->val));
        if(!root->left && !root->right){
            int tmp = cur, cnt = 0;
            while(tmp){
                cnt += (tmp & 1);
                tmp >>= 1;
            }
            if(cnt <= 1)
                ans++;
        }
        else{
            dfs(root->left, cur, ans);
            dfs(root->right, cur, ans);
        }
        cur ^= (1 << (root->val));
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0, cur = 0;
        dfs(root, cur, ans);
        return ans;
    }
};