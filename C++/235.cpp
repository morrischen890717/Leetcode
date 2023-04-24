/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *curr = root;
        while((p->val > curr->val && q->val > curr->val) || (p->val < curr->val && q->val < curr->val)){
            if(p->val > curr->val && q->val > curr->val)
                curr = curr->right;
            else
                curr = curr->left;
        }
        return curr;
    }
};