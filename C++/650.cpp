class Solution {
public:
    int solve(vector<int>& dp, int n){
        if(dp[n] != INT_MAX)
            return dp[n];
        for(int i = 1; i <= n; i++){
            if(n % i == 0)
                dp[n] = min(dp[n], solve(dp, i) + n / i); // (n/i) includes 1 copy and (n/i - 1) pastes
        }
        return dp[n];
    }
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        return solve(dp, n);
    }
};