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
    bool dfs(TreeNode* root, int& i, vector<int>& voyage, vector<int>& ans){
        if(!root)
            return true;
        if(root->val != voyage[i])
            return false;
        i++;
        if(!dfs(root->left, i, voyage, ans)){
            TreeNode *tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            if(!dfs(root->left, i, voyage, ans))
                return false;
            ans.push_back(root->val);
        }
        return dfs(root->right, i, voyage, ans);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        // using DFS
        vector<int> ans;
        int i = 0;
        if(!dfs(root, i, voyage, ans))
            ans = {-1};
        return ans;
    }
};