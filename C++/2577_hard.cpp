class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // using Dijkstra's Algorithm
        // time complexity: O(M * N * log(M * N)), space complexity: O(M * N), where M == grid.size() and N == grid[0].size()
        // reference: https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/solutions/3230800/c-java-python-ping-pong-dijkstra/?envType=daily-question&envId=2024-11-29
        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {1, 0, -1, 0, 1};
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        while(!pq.empty()){
            int time = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();
            if(i == m - 1 && j == n - 1)
                return time;
            if(visited[i][j])
                continue;
            visited[i][j] = true;
            for(int k = 0; k < 4; k++){
                int new_i = i + dirs[k], new_j = j + dirs[k + 1];
                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n){
                    int wait = (grid[new_i][new_j] - time) % 2 == 0 ? 1 : 0;
                    int new_time = max(time + 1, grid[new_i][new_j] + wait);
                    pq.push({new_time, {new_i, new_j}});
                }
            }
        }
        return -1;
    }
};