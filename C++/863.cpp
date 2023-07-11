/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getTarget(TreeNode* root, TreeNode* target, unordered_map<int, int>& dis){
        if(!root)
            return INT_MAX;
        if(root == target){
            dis[root->val] = 0;
            return 0;
        }
        int l = getTarget(root->left, target, dis);
        int r = getTarget(root->right, target, dis);
        if(l != INT_MAX){
            dis[root->val] = l + 1;
            return l + 1;
        } 
        else if(r != INT_MAX){
            dis[root->val] = r + 1;
            return r + 1;
        }
        return INT_MAX;
    }
    void dfs(TreeNode* root, unordered_map<int, int>& dis, int k, int d, vector<int>& ans){
        if(!root)
            return;
        if(dis.count(root->val) > 0)
            d = dis[root->val];
        if(d == k)
            ans.push_back(root->val);
        dfs(root->left, dis, k, d + 1, ans);
        dfs(root->right, dis, k, d + 1, ans);
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        /*
        using DFS + unordered_map
        reference: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/solutions/143798/1ms-beat-100-simple-java-dfs-with-without-hashmap-including-explanation/
        */
        vector<int> ans;
        unordered_map<int, int> dis; // stores all ths values of the nodes which are in the path from root to target
        getTarget(root, target, dis);
        dfs(root, dis, k, 0, ans);
        return ans;
    }
};