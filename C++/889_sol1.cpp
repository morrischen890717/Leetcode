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
private:
    int pre = 0, post = 0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // time complexity: O(N)
        // reference: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/solutions/161268/c-java-python-one-pass-real-o-n/
        TreeNode *root = new TreeNode(preorder[pre]);
        pre++;
        if(root->val != postorder[post])
            root->left = constructFromPrePost(preorder, postorder);
        if(root->val != postorder[post])
            root->right = constructFromPrePost(preorder, postorder);
        post++;
        return root;
    }
};