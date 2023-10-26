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
    int sumEvenGrandparent(TreeNode* root) {
        // using BFS
        // time complexity: O(N)
        int sum = 0;
        queue<pair<TreeNode*, int>> q; // {node, value of the parent of the node}
        q.push({root, 1});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<TreeNode*, int> p = q.front();
                q.pop();
                TreeNode *cur = p.first;
                if(cur->left){
                    if(p.second % 2 == 0)
                        sum += cur->left->val;
                    q.push({cur->left, cur->val});
                }
                if(cur->right){
                    if(p.second % 2 == 0)
                        sum += cur->right->val;
                    q.push({cur->right, cur->val});
                }
            }
        }
        return sum;
    }
};