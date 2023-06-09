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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool dir = true; // true: left to right, false: right to left
        while(!q.empty()){
            int n = q.size();
            vector<int> v(n);
            for(int i = 0; i < n; i++){
                TreeNode *node = q.front();
                q.pop();
                if(dir)
                    v[i] = node->val;  // from front to back
                else
                    v[n - 1 - i] = node->val; // from back to front
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(v);
            dir = !dir;
        }
        return ans;
    }
};