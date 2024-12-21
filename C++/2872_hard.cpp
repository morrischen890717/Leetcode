class Solution {
public:
    int dfs(vector<vector<int>>& graph, vector<int>& values, int prev, int cur, int k, int& ans){
        int sum = 0;
        for(int next: graph[cur]){
            if(next == prev)
                continue;
            sum += dfs(graph, values, cur, next, k, ans);
            sum %= k;
        }
        sum += values[cur];
        sum %= k;
        if(sum == 0)
            ans++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int ans = 0;
        vector<vector<int>> graph(n);
        for(vector<int>& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(graph, values, -1, 0, k, ans);
        return ans;
    }
};