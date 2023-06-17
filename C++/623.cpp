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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
            return new TreeNode(val, root, NULL);
        queue<TreeNode*> q;
        q.push(root);
        while(depth > 1){
            depth -= 1;
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode *parent = q.front();
                q.pop();
                if(depth == 1){
                    TreeNode *newLeft = new TreeNode(val, parent->left, NULL);
                    parent->left = newLeft;
                    TreeNode *newRight = new TreeNode(val, NULL, parent->right);
                    parent->right = newRight;
                }
                else{
                    if(parent->left)
                        q.push(parent->left);
                    if(parent->right)
                        q.push(parent->right);
                }
            }
        }
        return root;
    }
};