class Solution {
public:
    int dfs(vector<vector<int>>& graph, vector<int>& time, vector<int>& dp, int cur){
        if(graph[cur].empty())
            return dp[cur] = time[cur];
        if(dp[cur] != 0)
            return dp[cur];
        for(int next: graph[cur]){
            dp[cur] = max(dp[cur], time[cur] + dfs(graph, time, dp, next));
        }
        return dp[cur];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // using top-down DP and Topological Sort
        // time complexity: O(N + M), where M == relations.size()
        vector<vector<int>> graph(n);
        vector<int> dp(n, 0);
        for(vector<int>& relation: relations){
            graph[relation[0] - 1].push_back(relation[1] - 1);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, dfs(graph, time, dp, i));
        }
        return ans;
    }
};