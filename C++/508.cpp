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
    int dfs(TreeNode* node, unordered_map<int, int>& cnt){
        if(node == NULL)
            return 0;
        int sum = node->val + dfs(node->left, cnt) + dfs(node->right, cnt);
        cnt[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> cnt;
        dfs(root, cnt);
        int max_cnt = INT_MIN;
        for(auto it: cnt){
            max_cnt = max(max_cnt, it.second);
        }
        for(auto it: cnt){
            if(it.second == max_cnt)
                ans.push_back(it.first);
        }
        return ans;
    }
};