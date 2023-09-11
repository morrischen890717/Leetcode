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
    int maxAncestorDiff(TreeNode* root, int maxNum = INT_MIN, int minNum = INT_MAX) {
        // using DFS
        if(!root)
            return maxNum - minNum;
        maxNum = max(maxNum, root->val);
        minNum = min(minNum, root->val);
        return max(maxAncestorDiff(root->left, maxNum, minNum), maxAncestorDiff(root->right, maxNum, minNum));
    }
};