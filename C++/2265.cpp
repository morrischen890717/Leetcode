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
    pair<int, int> dfs(TreeNode* root, int& ans){ // return value: {sum, # of children}
        if(!root)
            return {0, 0};
        pair<int, int> l = dfs(root->left, ans), r = dfs(root->right, ans);
        int sum = l.first + r.first + root->val, cnt = l.second + r.second + 1;
        if(sum / cnt == root->val)
            ans++;
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        // using DFS
        // time complexity: O(N)
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};