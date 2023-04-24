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
    bool dfs(TreeNode* root, int depth, int max_depth, int& leaf_node){
        if(root == NULL)
            return false;
        if(depth == max_depth && root != NULL){
            leaf_node++;
            return true;
        }
        if(dfs(root->left, depth + 1, max_depth, leaf_node)){
            if(dfs(root->right, depth + 1, max_depth, leaf_node))
                return true;
        }
        return false;
    }
    int countNodes(TreeNode* root) {
        TreeNode *curr = root;
        int depth = 0;
        int r = 2;
        while(curr != NULL){
            depth += 1;
            curr = curr->left;
        }
        if(depth == 0)
            return 0;
        int internal_node = 1 * (1 - pow(2, depth - 1)) / (1 - r); // Geometric series
        int leaf_node = 0;
        dfs(root, 1, depth, leaf_node);
        return internal_node + leaf_node;
    }
};