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
    vector<int> dfs(TreeNode* root, int d, int& ans){
        vector<int> res(d + 1, 0);
        if(!root)
            return res;
        if(!root->left && !root->right){
            res[1] = 1;
            return res;
        }
        vector<int> left = dfs(root->left, d, ans), right = dfs(root->right, d, ans);
        for(int i = 1; i < d; i++){
            for(int j = 1; j <= d - i; j++){
                ans += left[i] * right[j];
            }
        }
        for(int i = 2; i <= d; i++){
            res[i] = left[i - 1] + right[i - 1];
        }
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        // using DFS
        // reference: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/solutions/756198/java-dfs-solution-with-a-twist-100-faster-explained/?envType=daily-question&envId=2024-07-18
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
};