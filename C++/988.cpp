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
    void dfs(TreeNode* root, string cur, string& ans){
        if(!root)
            return;
        char c = 'a' + root->val;
        cur = c + cur;
        if(!root->left && !root->right){
            if(cur < ans || ans == "")
                ans = cur;
            return;
        }
        dfs(root->left, cur, ans);
        dfs(root->right, cur, ans);
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        dfs(root, "", ans);
        return ans;
    }
};