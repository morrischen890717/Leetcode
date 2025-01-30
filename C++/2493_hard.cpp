class Solution {
public:
    int find(vector<int>& parent, int i){
        return i == parent[i] ? i : find(parent, parent[i]);
    }
    void uni(vector<int>& parent, int i, int j){
        int root_i = find(parent, i), root_j = find(parent, j);
        if(root_i != root_j)
            parent[root_i] = root_j;
        return;
    }
    int bfs(vector<vector<int>>& graph, int i){
        queue<int> q;
        q.push(i);
        int level = 0;
        unordered_map<int, int> visited; // {id, level}
        visited[i] = level;
        while(!q.empty()){
            int size = q.size();
            for(int j = 0; j < size; j++){
                int cur = q.front();
                q.pop();
                for(int next: graph[cur]){
                    if(visited.count(next)){
                        if(visited[next] == level)
                            return -1;
                    }
                    else{
                        visited[next] = level + 1;
                        q.push(next);
                    }
                }
            }
            level++;
        }
        return level;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // using BFS and Union-Find
        // reference: https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/solutions/2875991/python3-bfs-dfs-union-find-explained/?envType=daily-question&envId=2025-01-30
        vector<int> parent(n + 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        vector<vector<int>> graph(n + 1);
        for(vector<int>& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            uni(parent, edge[0], edge[1]);
        }
        unordered_map<int, int> root_depth;
        for(int i = 1; i <= n; i++){
            int level = bfs(graph, i);
            if(level == -1)
                return -1;
            int root = find(parent, i);
            root_depth[root] = max(root_depth[root], level);
        }
        int ans = 0;
        for(unordered_map<int, int>::iterator it = root_depth.begin(); it != root_depth.end(); it++){
            ans += it->second;
        }
        return ans;
    }
};