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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_start, int in_start, int in_end){
        if(in_start > in_end)
            return NULL;
        TreeNode *root = new TreeNode(preorder[pre_start]);
        int id;
        for(id = in_start; id <= in_end; id++){
            if(inorder[id] == preorder[pre_start])
                break;
        }
        root->left = build(preorder, inorder, pre_start + 1, in_start, id - 1);
        root->right = build(preorder, inorder, pre_start + id - in_start + 1, id + 1, in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder, inorder, 0, 0, n - 1);
    }
};