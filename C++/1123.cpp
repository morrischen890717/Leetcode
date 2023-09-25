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
    pair<int, TreeNode*> dfs(TreeNode* root, int depth){ // return value: {depth of deepest leaves, lowest common ancestor of the subtree with root = root}
        if(!root)
            return {depth, NULL};
        pair<int, TreeNode*> l = dfs(root->left, depth + 1);
        pair<int, TreeNode*> r = dfs(root->right, depth + 1);
        if(l.first == r.first)
            return {l.first, root};
        else if(l.first > r.first)
            return l;
        else
            return r;
        return {-1, NULL};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // using DFS
        // time complexity: O(N), space complexity: O(1)
        return dfs(root, 0).second;
    }
};