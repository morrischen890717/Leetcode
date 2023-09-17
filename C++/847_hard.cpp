class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // using BFS
        int n = graph.size();
        vector<vector<bool>> visited(n, vector<bool> (1 << n, false)); // dp[i][j] means that whether we have visited i-th node in status j before
        queue<pair<int, int>> q; // {nodeId, mask}
        for(int i = 0; i < n; i++){ // we start from all the nodes simultaneously
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> p = q.front();
                q.pop();
                int id = p.first, mask = p.second;
                if(mask == (1 << n) - 1)
                    return cnt;
                for(int next: graph[id]){
                    int new_mask = (1 << next) | mask;
                    if(!visited[next][new_mask]){ // if visited[next][new_mask] == true, it means that we have visited node {next} in status {new_mask} with smaller edge length
                        visited[next][new_mask] = true;
                        q.push({next, new_mask});
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};