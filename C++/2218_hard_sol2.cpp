class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        int m;
        int sum;
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
        for(int i = 1; i <= n; i++){
            m = piles[i - 1].size();
            for(int j = 0; j <= k; j++){
                sum = 0;
                dp[i][j] = dp[i - 1][j];
                for(int t = 1; t <= m && t <= j; t++){
                    sum += piles[i - 1][t - 1];
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - t] + sum);
                }
            }
        }
        return dp[n][k];
    }
};