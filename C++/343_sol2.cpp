class Solution {
public:
    int integerBreak(int n) {
        int dp[n + 1];
        memset(dp, 0, (n + 1) * sizeof(int));
        if(n == 2) return 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j <= i / 2 + 1; j++){
                dp[i] = max(dp[i], dp[i - j] * j);
            }
            if(dp[i] < i && i != n) dp[i] = i;
        }
        return dp[n];
    }
};