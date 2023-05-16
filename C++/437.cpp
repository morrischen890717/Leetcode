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
    void solve(TreeNode* node, int targetSum, vector<long long>& cur, int& ans){
        if(!node)
            return;
        cur.push_back(0); // represents current node itself only (0 + node->val = node->val)
        int n = cur.size();
        for(int i = 0; i < n; i++){
            cur[i] += node->val;
            if(cur[i] == targetSum)
                ans += 1;
        }
        solve(node->left, targetSum, cur, ans);
        solve(node->right, targetSum, cur, ans);
        for(int i = 0; i < n; i++){
            cur[i] -= node->val;
        }
        cur.pop_back(); // remove the value which only contains current node itself
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        vector<long long> cur;
        solve(root, targetSum, cur, ans);
        return ans;    
    }
};