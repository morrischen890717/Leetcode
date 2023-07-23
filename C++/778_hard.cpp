class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // main idea: this solution is similar to Dijkstra's Algorithm in graph problem
        int m = grid.size(), n = grid[0].size();
        if(m == 1 && n == 1)
            return grid[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // {grid[i][j], {i, j}}
        pq.push({grid[0][0], {0, 0}});
        int time = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while(!pq.empty()){
            int h = pq.top().first;
            pair<int, int> p = pq.top().second;
            pq.pop();
            if(grid[p.first][p.second] == INT_MAX) // visited
                continue;
            grid[p.first][p.second] = INT_MAX;
            time = max(time, h);
            for(int i = 0; i < 4; i++){
                int new_i = p.first + dirs[i], new_j = p.second + dirs[i + 1];
                if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || grid[new_i][new_j] == INT_MAX)
                    continue;
                if(new_i == m - 1 && new_j == n - 1){
                    time = max(time, grid[new_i][new_j]);
                    return time;
                }
                pq.push({grid[new_i][new_j], {new_i, new_j}});
            }
        }
        return -1;
    }
};