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
    int dfs(TreeNode* node, int parentSum){
        if(node == NULL)
            return 0;
        int rightSum = dfs(node->right, parentSum);
        int subtreeSum = rightSum + node->val;
        node->val = parentSum + subtreeSum;
        subtreeSum += dfs(node->left, node->val);
        return subtreeSum;
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
};