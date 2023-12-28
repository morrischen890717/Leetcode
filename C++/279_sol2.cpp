class Solution {
public:
    int square(int x){
        return x * x;
    }
    int numSquares(int n) {
        int dp[n + 1];
        for(int i = 0; i <= n; i++) dp[i] = i;
        for(int i = 0; i <= n; i++){
            for(int j = 1; square(j) <= i; j++){
                dp[i] = min(dp[i - square(j)] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};