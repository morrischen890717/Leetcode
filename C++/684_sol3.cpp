class Solution {
public:
    void dfs(vector<vector<int>>& neighbors, vector<bool>& visited, vector<int>& remove, int cur, int& cnt){
        if(visited[cur])
            return;
        visited[cur] = true;
        cnt++;
        for(int neighbor: neighbors[cur]){
            if((cur == remove[0] && neighbor == remove[1]) || (cur == remove[1] && neighbor == remove[0]))
                continue;
            dfs(neighbors, visited, remove, neighbor, cnt);
        }
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /*
        using DFS
        time complexity: O(N^2)
        */
        int n = edges.size();
        vector<vector<int>> neighbors(n + 1);
        for(vector<int>& edge: edges){
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        for(int i = n - 1; i >= 0; i--){
            vector<bool> visited(n + 1, false);
            int cnt = 0;
            dfs(neighbors, visited, edges[i], 1, cnt);
            if(cnt == n)
                return edges[i];
        }
        return {-1, -1};
    }
};