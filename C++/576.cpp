class Solution {
public:
    const int MOD = 1e9 + 7;
    int dfs(int m, int n, int i, int j, vector<int>& dir, vector<vector<vector<int>>>& dp, int maxMove){
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 1;
        if(maxMove <= 0)
            return 0;
        if(dp[maxMove][i][j] != -1)
            return dp[maxMove][i][j];
        long long num = 0;
        for(int k = 0; k < 4; k++){
            num += dfs(m, n, i + dir[k], j + dir[k + 1], dir, dp, maxMove - 1);
            num %= MOD;
        }
        return dp[maxMove][i][j] = num;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>> (m, vector<int> (n, -1)));
        vector<int> dir = {1, 0, -1, 0, 1};
        return dfs(m, n, startRow, startColumn, dir, dp, maxMove);
    }
};