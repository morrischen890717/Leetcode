class Solution {
public:
    int getMoneyAmount(int n) {
        // bottom-up DP method
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));
        for(int i = n; i >= 1; i--){
            for(int j = i + 1; j <= n; j++){
                dp[i][j] = INT_MAX;
                for(int k = i; k <= j; k++){
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};