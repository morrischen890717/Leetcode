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
    void traverse(TreeNode* node, int num, int& ans){
        num *= 10;
        num += node->val;
        if(node->left == NULL && node->right == NULL){
            ans += num;
            return;
        }
        if(node->left != NULL)
            traverse(node->left, num, ans);
        if(node->right != NULL)
            traverse(node->right, num, ans);
        return;
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        traverse(root, 0, ans);
        return ans;
    }
};