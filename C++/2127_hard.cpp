class Solution {
public:
    int dfs(vector<vector<int>>& graph, vector<bool>& visited, int cur){
        int res = 1;
        for(int next: graph[cur]){
            if(!visited[next]){
                visited[next] = true;
                res = max(res, 1 + dfs(graph, visited, next));
            }
        }
        return res;
    }
    int dfs2(vector<vector<int>>& graph, vector<bool>& visited, int start, int cur){
        if(visited[cur])
            return 0;
        visited[cur] = true;
        for(int next: graph[cur]){
            if(next == start)
                return 1;
            int res = dfs2(graph, visited, start, next);
            if(res)
                return 1 + res;
        }
        return 0;
    }
    int maximumInvitations(vector<int>& favorite) {
        // using DFS
        // reference: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/solutions/1660944/c-dfs-with-illustration/?envType=daily-question&envId=2025-01-26
        int ans = 0, res = 0;
        int n = favorite.size();
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            graph[favorite[i]].push_back(i);
        }
        for(int i = 0; i < n; i++){
            if(visited[i])
                continue;
            if(i == favorite[favorite[i]]){
                visited[i] = visited[favorite[i]] = true;
                ans += dfs(graph, visited, i) + dfs(graph, visited, favorite[i]);
            }
        }
        visited = vector<bool> (n, false);
        for(int i = 0; i < n; i++){
            if(visited[i])
                continue;
            res = max(res, dfs2(graph, visited, i, i));
        }
        return max(ans, res);
    }
};