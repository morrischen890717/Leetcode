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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        while(!q.empty()){
            int n = q.size(), sum = 0;
            vector<TreeNode*> tmp;
            for(int i = 0; i < n; i++){
                TreeNode *cur = q.front();
                q.pop();
                tmp.push_back(cur);
                if(cur->left){
                    sum += cur->left->val;
                    q.push(cur->left);
                }
                if(cur->right){
                    sum += cur->right->val;
                    q.push(cur->right);  
                }
            }
            for(TreeNode* node: tmp){
                int minus = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
                if(node->left)
                    node->left->val = sum - minus;
                if(node->right)  
                    node->right->val = sum - minus;
            }
        }
        return root;
    }
};