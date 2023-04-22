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
    TreeNode* dfs(TreeNode* node){  // this approach can use just O(1) extra space to flatten the tree
        if(node == NULL)
            return NULL;
        /*
        left_leaf represents the leaf node of left side after left side have been flatten(all nodes below node->left have moved to right side of node->left)
        right_leaf represents the leaf node of right side after right side have been flatten(all nodes below node->right have moved to right side of node->right)
        */
        TreeNode *left_leaf = dfs(node->left);
        TreeNode *right_leaf = dfs(node->right);
        if(left_leaf != NULL && right_leaf != NULL){
            left_leaf->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        else if(left_leaf != NULL && right_leaf == NULL){
            node->right = node->left;
            node->left = NULL;
            right_leaf = left_leaf;
        }
        else if(left_leaf == NULL && right_leaf == NULL){
            right_leaf = node;
        }
        return right_leaf;
    }
    void flatten(TreeNode* root) {
        dfs(root);
        return;
    }
};