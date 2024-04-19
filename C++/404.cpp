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
    int sumOfLeftLeaves(TreeNode* root) {
        // using DFS
        if(!root)
            return 0;
        int sum = root->left && !root->left->left && !root->left->right? root->left->val : 0;
        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right); 
    }
};