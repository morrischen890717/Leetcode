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
    void dfs(TreeNode* root, unordered_map<int, vector<int>>& graph){
        if(!root)
            return;
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            dfs(root->left, graph);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            dfs(root->right, graph);
        }
        return;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        dfs(root, graph);
        int len = -1;
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();
                for(int next: graph[cur]){
                    if(visited.count(next) == 0){
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            len++;
        }
        return len;
    }
};