class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<int>& dirs){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int step = 1;
        while(!q.empty()){
            int size = q.size();
            for(int t = 0; t < size; t++){
                pair<int, int> p = q.front();
                q.pop();
                for(int k = 0; k < 4; k++){
                    int new_i = p.first + dirs[k], new_j = p.second + dirs[k + 1];
                    if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !visited[new_i][new_j]){
                        grid[new_i][new_j] = step;
                        visited[new_i][new_j] = true;
                        q.push({new_i, new_j});
                    }
                }
            }
            step++;
        }
        return;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // using BFS, priority_queue and Dijkstra's Algorithm
        // time comlpexity: O(M * N * log(M * N)), space complexity: O(M * N), where M == grid.size() and N == grid[0].size()
        // reference: https://leetcode.com/problems/find-the-safest-path-in-a-grid/solutions/5158873/fastest-100-easy-to-understand-clean-concise/?envType=daily-question&envId=2024-05-15
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        bfs(grid, dirs);
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        while(!pq.empty()){
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int d = p.first, i = p.second.first, j = p.second.second;
            if(i == m - 1 && j == n - 1)
                return d;
            for(int k = 0; k < 4; k++){
                int new_i = i + dirs[k], new_j = j + dirs[k + 1];
                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !visited[new_i][new_j]){
                    visited[new_i][new_j] = true;
                    int new_d = min(d, grid[new_i][new_j]);
                    pq.push({new_d, {new_i, new_j}});
                }
            }
        }
        return -1;
    }
};