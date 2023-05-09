class Solution {
public:
    int solve(int l, int r, vector<vector<int>>& dp){
        if(l >= r)
            return 0;
        if(dp[l][r] != INT_MAX)
            return dp[l][r];
        for(int i = l; i <= r; i++){
            dp[l][r] = min(dp[l][r], i + max(solve(l, i - 1, dp), solve(i + 1, r, dp)));
        }
        return dp[l][r];
    }
    int getMoneyAmount(int n) {
        // top-down DP method
        int ans = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, INT_MAX));
        return solve(1, n, dp);
    }
};