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
    void dfs(TreeNode* root, string s, string& ans){
        char c = 'a' + root->val;
        s = c + s;
        if(!root->left && !root->right){
            if(ans == ".")
                ans = s;
            int min_len = min(s.length(), ans.length());
            string sub_s = s.substr(0, min_len), sub_ans = ans.substr(0, min_len);
            if(sub_s == sub_ans && s.length() < ans.length())
                ans = s;
            else
                ans = sub_s < sub_ans ? s : ans;
            return;
        }
        if(root->left)
            dfs(root->left, s, ans);
        if(root->right)
            dfs(root->right, s, ans);
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = ".";
        dfs(root, "", ans);
        return ans;
    }
};