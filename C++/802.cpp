class Solution {
public:
    char dfs(vector<vector<int>>& graph, vector<char>& dp, int i){
        if(dp[i] != 0)
            return dp[i];
        dp[i] = 2; // visited
        for(int adj: graph[i]){
            if(dfs(graph, dp, adj) == 2)
                return dp[i] = 2;
        }
        return dp[i] = 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // dp[i] == 0 stands for not visited yet, dp[i] == 1 stands for the node is a safe node, dp[i] == 2 stands for the node is not a safe node
        vector<char> dp(n, 0);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(dfs(graph, dp, i) == 1)
                ans.push_back(i);
        }
        return ans;
    }
};