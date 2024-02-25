class Solution {
public:
    int solve(vector<int>& dp, int state, int n, int i){
        if(i == n)
            return 1;
        if(dp[state] != -1)
            return dp[state];
        dp[state] = 0;
        for(int j = 0; j < n; j++){
            if(state & (1 << j) || ((j + 1) % (i + 1) && (i + 1) % (j + 1)))
                continue;
            dp[state] += solve(dp, state | (1 << j), n, i + 1);
        }
        return dp[state];
    }
    int countArrangement(int n) {
        // using top-down DP and bit manipulation
        vector<int> dp(1 << n, -1);
        dp[(1 << n) - 1] = 1;
        return solve(dp, 0, n, 0);
    }
};