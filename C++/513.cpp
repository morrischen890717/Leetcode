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
    void dfs(TreeNode* node, int h, pair<int, int>& p){
        if(node->left == NULL && node->right == NULL){
            if(h > p.first){
                p = {h, node->val};
            }
            return;
        }
        if(node->left != NULL)
            dfs(node->left, h + 1, p);
        if(node->right != NULL)
            dfs(node->right, h + 1, p);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        pair<int, int> p = {-1, -1}; // p = {height, value}
        dfs(root, 0, p);
        return p.second;
    }
};