class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int i, int group){
        if(visited[i] != -1)
            return visited[i] == group;
        visited[i] = group;
        for(int j = 0; j < graph[i].size(); j++){
            if(!dfs(graph, visited, graph[i][j], group ^ 1))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        for(int i = 0; i < n; i++){
            if(!dfs(graph, visited, i, visited[i]))
                return false;
        }
        return true;
    }
};