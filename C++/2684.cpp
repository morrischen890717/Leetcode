class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        // using bottom-up
        // time complexity: O(M * N), space complexity: O(M * N), where M == grid.size() and N == grid[0].size()
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int j = n - 1; j >= 1; j--){
            for(int i = 0; i < m; i++){
                for(int k = -1; k <= 1; k++){
                    if(i + k >= 0 && i + k < m && grid[i][j] > grid[i + k][j - 1])
                        dp[i + k][j - 1] = max(dp[i + k][j - 1], dp[i][j] + 1);
                }
            }
        }
        for(int i = 0; i < m; i++){
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};