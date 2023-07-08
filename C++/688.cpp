class Solution {
public:
    double dfs(vector<vector<vector<double>>>& dp, vector<int>& dirs, int n, int k, int row, int column){
        if(row < 0 || row >= n || column < 0 || column >= n)
            return 0.0;
        if(k == 0)
            return dp[row][column][k] = 1.0;
        if(dp[row][column][k] != -1.0)
            return dp[row][column][k];
        dp[row][column][k] = 0.0;
        for(int i = 0; i < 8; i++){
            dp[row][column][k] += dfs(dp, dirs, n, k - 1, row + dirs[i], column + dirs[i + 1]) / 8;
        }
        return dp[row][column][k];
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>> (n, vector<double> (k + 1, -1.0)));
        vector<int> dirs = {-2, -1, 2, -1, -2, 1, 2, 1, -2};
        return dfs(dp, dirs, n, k, row, column);
    }
};