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
    string dfs(TreeNode *root, unordered_map<string, bool> &m, vector<TreeNode*> &ans){
        if(!root)
            return "";
        // postorder traversal
        string left = dfs(root->left, m, ans);
        string right = dfs(root->right, m, ans);
        string s = "(" + left + to_string(root->val) + right + ")";
        if(m.count(s) == 0)
            m[s] = true;
        else if(m[s] == true){
            ans.push_back(root);
            m[s] = false; 
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, bool> m;
        dfs(root, m, ans);
        return ans;   
    }
};