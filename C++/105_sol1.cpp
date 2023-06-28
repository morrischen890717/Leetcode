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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& m, int pre_start, int in_start, int in_end){
        if(in_start > in_end)
            return NULL;
        TreeNode *root = new TreeNode(preorder[pre_start]);
        int id = m[preorder[pre_start]];
        root->left = build(preorder, inorder, m, pre_start + 1, in_start, id - 1);
        root->right = build(preorder, inorder, m, pre_start + id - in_start + 1, id + 1, in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> m;
        for(int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        return build(preorder, inorder, m, 0, 0, n - 1);
    }
};