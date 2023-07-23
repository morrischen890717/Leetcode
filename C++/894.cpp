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
    vector<TreeNode*> allPossibleFBT(int n) {
        // using bottom-up DP
        vector<vector<TreeNode*>> dp(n + 1);
        dp[1].push_back(new TreeNode(0));
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i - 1; j++){
                if(!dp[j].empty() && !dp[i - 1 - j].empty()){ // size of left + size of right should be i - 1, and both of them should not be empty(otherwise it is not full binary tree)
                    for(TreeNode *l: dp[j]){ // left subtree
                        for(TreeNode *r: dp[i - 1 - j]){ // right subtree
                            dp[i].push_back(new TreeNode(0, l, r));
                        }
                    }
                }
            }
        }
        return dp[n];
    }
};