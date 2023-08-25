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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // using DFS
        if(root1 == NULL || root2 == NULL){
            return root1 == root2;
        }
        if(root1->val != root2->val)
            return false;
        int root1Left = root1->left ? root1->left->val : -1;
        int root1Right = root1->right ? root1->right->val : -1;
        int root2Left = root2->left ? root2->left->val : -1;
        int root2Right = root2->right ? root2->right->val : -1;
        if(root1Left != root2Left || root1Right != root2Right){
            if(root1Right == root2Left && root1Left == root2Right){
                TreeNode *l = root1->left;
                root1->left = root1->right;
                root1->right = l;
            }
            else
                return false;
        }
        return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
    }
};