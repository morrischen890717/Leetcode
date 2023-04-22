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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){  // bfs
            int n = q.size();
            ans.push_back(q.front()->val);
            for(int i = 0; i < n; i++){
                TreeNode *cur = q.front();
                q.pop();
                if(cur->right != NULL)
                    q.push(cur->right);
                if(cur->left != NULL)
                    q.push(cur->left);
            }
        }
        return ans;
    }
};