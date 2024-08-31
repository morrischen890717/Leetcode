class Solution {
public:
    void dfs(vector<vector<int>>& graph, int start, int cur, vector<vector<int>>& ans){
        for(int next: graph[cur]){
            if(ans[next].empty() || ans[next].back() != start){
                ans[next].push_back(start);
                dfs(graph, start, next, ans);
            }
        }
        return;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // reference: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/solutions/1822108/c-solution-plain-dfs-short-and-clean-code/?envType=daily-question&envId=2024-06-29
        vector<vector<int>> ans(n);
        vector<vector<int>> graph(n);
        for(vector<int>& edge: edges){
            graph[edge[0]].push_back(edge[1]);
        }
        for(int i = 0; i < n; i++){
            dfs(graph, i, i, ans);
        }
        return ans;
    }
};