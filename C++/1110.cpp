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
    TreeNode* solve(TreeNode* cur, unordered_set<int>& s, bool is_root, vector<TreeNode*>& ans){
        if(!cur)
            return NULL;
        if(s.count(cur->val) > 0)
            is_root = true;
        else if(is_root){
            ans.push_back(cur);
            is_root = false;
        }
        cur->left = solve(cur->left, s, is_root, ans);
        cur->right = solve(cur->right, s, is_root, ans);
        return s.count(cur->val) > 0 ? NULL : cur;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // using unordered_set and DFS
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        solve(root, s, true, ans);
        return ans;
    }
};