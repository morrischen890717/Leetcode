class Solution {
public:
    bool dfs1(vector<vector<int>>& graph, vector<int>& visited, int cur){
        visited[cur] = 1;
        for(int next: graph[cur]){
            if(visited[next] == 1)
                return true;
            else if(visited[next] == 0 && dfs1(graph, visited, next))
                return true;
        }
        visited[cur] = 2;
        return false;
    }
    bool isCyclic(vector<vector<int>>& graph, int k){
        vector<int> visited(k, 0);
        for(int i = 0; i < k; i++){
            if(visited[i] == 0 && dfs1(graph, visited, i))
                return true;
        }
        return false;
    }
    void dfs2(vector<vector<int>>& graph, vector<bool>& visited, int cur, vector<int>& res){
        visited[cur] = true;
        for(int next: graph[cur]){
            if(!visited[next])
                dfs2(graph, visited, next, res);
        }
        res.push_back(cur);
        return;
    }
    vector<int> topologicalSort(vector<vector<int>>& graph, int k){
        vector<int> res;
        vector<bool> visited(k, false);
        for(int i = 0; i < k; i++){
            if(!visited[i])
                dfs2(graph, visited, i, res);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // using topological sort
        // reference: https://leetcode.com/problems/build-a-matrix-with-conditions/solutions/2492728/c-with-explanation-simple-topological-sort-implementation/?envType=daily-question&envId=2024-07-21
        vector<vector<int>> ans(k, vector<int> (k, 0));
        vector<vector<int>> graph_row(k), graph_col(k);
        for(vector<int>& cond: rowConditions){
            graph_row[cond[0] - 1].push_back(cond[1] - 1);
        }
        for(vector<int>& cond: colConditions){
            graph_col[cond[0] - 1].push_back(cond[1] - 1);
        }
        if(isCyclic(graph_row, k) || isCyclic(graph_col, k))
            return {};
        vector<int> topological_row = topologicalSort(graph_row, k);
        vector<int> topological_col = topologicalSort(graph_col, k);
        unordered_map<int, int> m;
        for(int i = 0; i < k; i++){
            m[topological_col[i]] = i;
        }
        for(int i = 0; i < k; i++){
            ans[i][m[topological_row[i]]] = topological_row[i] + 1;
        }
        return ans;
    }
};