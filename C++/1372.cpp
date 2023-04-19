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
    int zigzag(TreeNode *node, int dir, int len){
        if(node == NULL)
            return len;
        int max_len;
        if(dir == 0) // left
            max_len = max(zigzag(node->right, 1, len + 1), zigzag(node->left, 0, 0));
        else
            max_len = max(zigzag(node->left, 0, len + 1), zigzag(node->right, 1, 0));
        return max_len;
    }
    int longestZigZag(TreeNode* root) {
        return max(zigzag(root->left, 0, 0), zigzag(root->right, 1, 0));
    }
};