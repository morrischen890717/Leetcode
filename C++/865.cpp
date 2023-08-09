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
    pair<int, TreeNode*> dfs(TreeNode* root, int depth){
        if(!root)
            return {depth, root};
        pair<int, TreeNode*> l = dfs(root->left, depth + 1);
        pair<int, TreeNode*> r = dfs(root->right, depth + 1);
        if(l.first > r.first)
            return l;
        else if(r.first > l.first)
            return r;
        return {l.first, root};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // using DFS
        // time complexity: O(N)
        pair<int, TreeNode*> p = dfs(root, 0); // {maxDepth, smallest subtree with maxDepth}
        return p.second;
    }
};