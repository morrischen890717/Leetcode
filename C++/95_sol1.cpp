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
    TreeNode* copy(TreeNode* target, int diff){
        if(target == NULL)
            return NULL;
        TreeNode *copied = new TreeNode(target->val + diff);
        copied->left = copy(target->left, diff);
        copied->right = copy(target->right, diff);
        return copied;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(n + 1, vector<TreeNode*> ());
        dp[0].push_back(NULL);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){  // j represent the value of root node
                for(int k = 0; k < dp[j - 1].size(); k++){  // # of nodes in left side: j - 1
                    for(int t = 0; t < dp[i - j].size(); t++){ // # of nodes in right side: i - j
                        TreeNode *root = new TreeNode(j);
                        root->left = copy(dp[j - 1][k], 0);
                        root->right = copy(dp[i - j][t], j);  // all value in right side should plus j
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }
};