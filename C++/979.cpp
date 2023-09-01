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
    int dfs(TreeNode* root, int& ans){
        if(!root)
            return 0;
        int l = dfs(root->left, ans), r = dfs(root->right, ans);
        ans += abs(l) + abs(r);
        return root->val + l + r - 1;
    }
    int distributeCoins(TreeNode* root) {
        // using post-order DFS
        // time complexity: O(N)
        // reference: https://leetcode.com/problems/distribute-coins-in-binary-tree/solutions/221930/java-c-python-recursive-solution/
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};