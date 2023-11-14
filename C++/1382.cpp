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
    TreeNode* solve(vector<TreeNode*>& v, int start, int end){
        if(start > end)
            return NULL;
        int mid = start + (end - start) / 2;
        v[mid]->left = solve(v, start, mid - 1);
        v[mid]->right = solve(v, mid + 1, end);
        return v[mid];
    }
    void dfs(TreeNode* root, vector<TreeNode*>& v){
        if(!root)
            return;
        dfs(root->left, v);
        v.push_back(root);
        dfs(root->right, v);
        return;
    }
    TreeNode* balanceBST(TreeNode* root) {
        // using DFS(inorder traversal) and Divide-and-Conquer
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/balance-a-binary-search-tree/solutions/539686/java-c-sorted-array-to-bst-o-n-clean-code/
        vector<TreeNode*> v;
        dfs(root, v);
        return solve(v, 0, v.size() - 1);
    }
};