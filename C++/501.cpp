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
    void dfs(TreeNode* root, int& cnt, int& prev, int& max_cnt, vector<int>& ans){
        if(!root)
            return;
        dfs(root->left, cnt, prev, max_cnt, ans);
        if(root->val != prev){
            if(cnt > max_cnt){
                max_cnt = cnt;
                ans = {prev};
            }
            else if(cnt == max_cnt)
                ans.push_back(prev);
            cnt = 0;
            prev = root->val;
        }
        cnt++;
        dfs(root->right, cnt, prev, max_cnt, ans);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        // using DFS(inorder traversal)
        // time complexity: O(N)
        int cnt = 0, max_cnt = 0;
        int prev = INT_MIN;
        vector<int> ans;
        dfs(root, cnt, prev, max_cnt, ans);
        if(cnt > max_cnt){
            max_cnt = cnt;
            ans = {prev};
        }
        else if(cnt == max_cnt)
            ans.push_back(prev);
        return ans;
    }
};