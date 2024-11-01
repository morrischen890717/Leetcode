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
    void dfs(TreeNode* root, unordered_map<int, int>& m, int h, int& max_h){
        if(!root)
            return;
        m[root->val] = max(m[root->val], max_h);
        max_h = max(max_h, h);
        dfs(root->left, m, h + 1, max_h);
        dfs(root->right, m, h + 1, max_h);
        return;
    }

    void reverse_dfs(TreeNode* root, unordered_map<int, int>& m, int h, int& max_h){
        if(!root)
            return;
        m[root->val] = max(m[root->val], max_h);
        max_h = max(max_h, h);
        reverse_dfs(root->right, m, h + 1, max_h);
        reverse_dfs(root->left, m, h + 1, max_h);
        return;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // using DFS
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/solutions/2759353/c-python-preoder-and-postorder-dfs/?envType=daily-question&envId=2024-10-26
        vector<int> ans;
        unordered_map<int, int> m;
        int max_h = 0;
        dfs(root, m, 0, max_h);
        max_h = 0;
        reverse_dfs(root, m, 0, max_h);
        for(int q: queries){
            ans.push_back(m[q]);
        }
        return ans;
    }
};