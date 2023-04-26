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
    void dfs(TreeNode* node, int k, int& num, int& ans){
        if(!node || num >= k)
            return;
        dfs(node->left, k, num, ans);
        num++;
        if(num == k){
            ans = node->val;
            return;
        }
        dfs(node->right, k, num, ans);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int num = 0;
        dfs(root, k, num, ans);
        return ans;
    }
};