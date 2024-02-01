class Solution {
public:
    int kInversePairs(int n, int k) {
        // using bottom-up DP
        // time complexity: O(K * N), space complexity: O(K * N)
        // reference: https://leetcode.com/problems/k-inverse-pairs-array/solutions/104815/java-dp-o-nk-solution/?envType=daily-question&envId=2024-01-27
        const int MOD = 1e9 + 7;
        if(k == 0 || k == n * (n - 1) / 2)
            return 1;
        else if(k < 0 || k > n * (n - 1) / 2)
            return 0;
        vector<vector<long long>> dp(n + 1, vector<long long> (k + 1, 0));
        dp[2][0] = 1;
        dp[2][1] = 1;
        for(int i = 3; i <= n; i++){
            dp[i][0] = 1;
            for(int j = 1; j <= min(k, i * (i - 1) / 2); j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - (j >= i ? dp[i - 1][j - i] : 0);
                dp[i][j] = (dp[i][j] + MOD) % MOD;
            }
        }
        return dp[n][k];
    }
};