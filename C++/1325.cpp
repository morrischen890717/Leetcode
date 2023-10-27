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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // using DFS
        // time complexity: O(N)
        if(!root)
            return NULL;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        return !root->left && !root->right && root->val == target ? NULL : root;
    }
};