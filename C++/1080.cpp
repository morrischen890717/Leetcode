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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        // using DFS
        // time complexity: O(N)
        if(!root)
            return NULL;
        limit -= root->val;
        if(root->left == root->right) // leaf node
            return limit > 0 ? NULL : root;
        root->left = sufficientSubset(root->left, limit);
        root->right = sufficientSubset(root->right, limit);
        return root->left == root->right ? NULL : root; // left path and right path both with the sums which strictly less than limit
    }
};