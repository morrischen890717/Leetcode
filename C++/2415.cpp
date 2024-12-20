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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> val;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode *cur = q.front();
                q.pop();
                if(level % 2){
                    cur->val = val.back();
                    val.pop_back();
                }
                else if(cur->left){
                    val.push_back(cur->left->val);
                    val.push_back(cur->right->val);
                }
                if(cur->left){
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            level++;
        }
        return root;
    }
};