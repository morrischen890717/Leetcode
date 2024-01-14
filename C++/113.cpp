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
    void solve(TreeNode* root, int targetSum, vector<int>& cur, int& curSum, vector<vector<int>>& ans){
        if(!root)
            return;
        cur.push_back(root->val);
        curSum += root->val;
        if(!root->left && !root->right){
            if(curSum == targetSum)
                ans.push_back(cur);
        }
        else{
            solve(root->left, targetSum, cur, curSum, ans);
            solve(root->right, targetSum, cur, curSum, ans);
        }
        cur.pop_back();
        curSum -= root->val;
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> cur;
        int curSum = 0;
        solve(root, targetSum, cur, curSum, ans);
        return ans;
    }
};