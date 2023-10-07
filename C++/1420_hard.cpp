class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        // using bottom-up DP
        // reference: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/solutions/586576/c-bottom-up-dynamic-programming-with-explanation/?envType=daily-question&envId=2023-10-07
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> (k + 1, 0)));
        vector<vector<vector<int>>> prefix(n + 1, vector<vector<int>> (m + 1, vector<int> (k + 1, 0))); // prefix[i][j][k] stands for the prefix sum of dp[i][1][k] ~ dp[i][j][k]
        for(int j = 1; j <= m; j++){
            dp[1][j][1] = 1;
            prefix[1][j][1] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int t = 1; t <= k; t++){
                    dp[i][j][t] += prefix[i - 1][j - 1][t - 1];
                    dp[i][j][t] %= MOD;
                    dp[i][j][t] += ((long long)j * dp[i - 1][j][t]) % MOD;
                    dp[i][j][t] %= MOD;
                    prefix[i][j][t] = dp[i][j][t] + prefix[i][j - 1][t];
                    prefix[i][j][t] %= MOD;
                }
            }
        }
        int ans = 0;
        for(int j = 1; j <= m; j++){
            ans += dp[n][j][k];
            ans %= MOD;
        }
        return ans;
    }
};