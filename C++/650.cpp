class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(dp[n] != INT_MAX)
            return dp[n];
        for(int i = 1; i <= sqrt(n); i++){
            if(n % i == 0){
                int j = n / i; // n = i * j (j times of i or i times of j)
                if(i != 1) // avoid infinite loop
                    dp[n] = min(dp[n], solve(j, dp) + i); // copy 1 time, paste i - 1 times
                dp[n] = min(dp[n], solve(i, dp) + j); // copy 1 time, paste j - 1 time
            }
        }
        return dp[n];
    }
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        return solve(n, dp);
    }
};