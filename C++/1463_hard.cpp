class Solution {
public:
    int maxCollect(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int m, int n, int i, int j1, int j2){
        if(i == m)
            return 0;
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        for(int k = -1; k <= 1; k++){
            for(int t = -1; t <= 1; t++){
                int new_j1 = j1 + k, new_j2 = j2 + t;
                if(new_j1 >= 0 && new_j1 < n && new_j2 >= 0 && new_j2 < n)
                    dp[i][j1][j2] = max(dp[i][j1][j2], maxCollect(grid, dp, m, n, i + 1, new_j1, new_j2));
            }
        }
        dp[i][j1][j2] += j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        return dp[i][j1][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        // using top-down DP
        // time complexity: O(9 * M * N^2), space complexity: O(M * N^2), where M == grid.size() and N == grid[0].size()
        // reference: https://leetcode.com/problems/cherry-pickup-ii/?envType=daily-question&envId=2024-02-11
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, -1)));
        return maxCollect(grid, dp, m, n, 0, 0, n - 1);
    }
};