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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int n;
        long long leftmost_id;
        TreeNode *cur;
        long long id;
        while(!q.empty()){  // bfs
            n = q.size();
            leftmost_id = q.front().second;
            for(int i = 0; i < n; i++){
                cur = q.front().first;
                id = q.front().second;
                q.pop();
                if(cur->left != NULL){
                    q.push({cur->left, (id - leftmost_id) * 2});
                }
                if(cur->right != NULL){
                    q.push({cur->right, (id - leftmost_id) * 2 + 1});
                }
            }
            ans = max(ans, (int)(id - leftmost_id + 1));
        }
        return ans;
    }
};