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
    int get_right_subtree_min(TreeNode* cur){
        return cur->left ? get_right_subtree_min(cur->left) : cur->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        else if(!root->right)
            return root->left;
        else if(!root->left)
            return root->right;
        else{
            int new_val = get_right_subtree_min(root->right);
            root->val = new_val;
            root->right = deleteNode(root->right, new_val);
        }
        return root;
    }
};