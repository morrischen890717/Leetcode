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
    string tree2str(TreeNode* root) {
        string s;
        solve(root, s);
        return s;
    }
    void solve(TreeNode* root, string& ans){
        if(!root)
            return;
        ans += to_string(root->val);
        if(root->right){
            ans += '(';
            ans += tree2str(root->left);
            ans += ')';
            ans += '(';
            ans += tree2str(root->right);
            ans += ')';
        }
        else if(root->left){
            ans += '(';
            ans += tree2str(root->left);
            ans += ')';
        }
        return;
    }
};