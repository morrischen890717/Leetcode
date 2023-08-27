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
    bool isCompleteTree(TreeNode* root) {
        // using BFS
        queue<TreeNode*> q;
        q.push(root);
        bool metNULL = false;
        while(!q.empty()){
            if(!q.front())
                metNULL = true;
            else if(metNULL)
                return false;
            else{
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
        }
        return true;
    }
};