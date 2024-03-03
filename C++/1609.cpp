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
    bool isEvenOddTree(TreeNode* root) {
        // using BFS
        // time complexity: O(N)
        bool even_level = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int prev = even_level ? INT_MIN : INT_MAX;
            for(int i = 0; i < n; i++){
                TreeNode *cur = q.front();
                q.pop();
                if(even_level){
                    if(cur->val % 2 == 0 || cur->val <= prev)
                        return false;
                    prev = cur->val;
                }
                else{
                    if(cur->val % 2 || cur->val >= prev)
                        return false;
                    prev = cur->val;
                }
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            even_level = !even_level;
        }
        return true;
    }
};