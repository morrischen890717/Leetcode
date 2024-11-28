class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        // using BFS
        // reference: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/solutions/2086235/0-1-bfs-c/?envType=daily-question&envId=2024-11-28
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {1, 0, -1, 0, 1};
        vector<vector<int>> dp(m, vector<int> (n, INT_MAX));
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        deque<pair<int, int>> q;
        q.push_front({0, 0});
        dp[0][0] = 0;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop_front();
            int x = p.first, y = p.second;
            for(int i = 0; i < 4; i++){
                int new_x = x + dirs[i], new_y = y + dirs[i + 1];
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n){
                    if(!visited[new_x][new_y]){
                        visited[new_x][new_y] = true;
                        dp[new_x][new_y] = dp[x][y] + grid[x][y];
                        if(grid[new_x][new_y])
                            q.push_back({new_x, new_y});
                        else
                            q.push_front({new_x, new_y});
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};