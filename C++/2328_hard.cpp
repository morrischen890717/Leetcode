class Solution {
public:
    bool inside(int m, int n, int i, int j){
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int dfs(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp, vector<int>& dir, int i, int j){
        if(dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int next_i = i + dir[k], next_j = j + dir[k + 1];
            if(inside(m, n, next_i, next_j) && grid[next_i][next_j] > grid[i][j]){
                dp[i][j] += dfs(grid, m, n, dp, dir, next_i, next_j);
                dp[i][j] %= (int)(1e9 + 7);
            }
        }
        return dp[i][j];
    }
    int countPaths(vector<vector<int>>& grid) {
        // using top-down DP with DFS
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        vector<int> dir = {1, 0, -1, 0, 1};
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans += dfs(grid, m, n, dp, dir, i, j);
                ans %= (int)(1e9 + 7);
            }
        }
        return ans;
    }
};