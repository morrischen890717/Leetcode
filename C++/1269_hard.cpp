class Solution {
public:
    int solve(vector<vector<int>>& dp, int arrLen, int i, int steps){
        if(i == 0 && steps == 0)
            return 1;
        else if(i < 0 || i >= arrLen || i > steps)
            return 0;
        else if(dp[steps][i] != -1)
            return dp[steps][i];
        return dp[steps][i] = ((long long)solve(dp, arrLen, i - 1, steps - 1) + solve(dp, arrLen, i + 1, steps - 1) + solve(dp, arrLen, i, steps - 1)) % (int)(1e9 + 7);
    }
    int numWays(int steps, int arrLen) {
        // reference: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/solutions/436117/c-recursive-dp-memoization/?envType=daily-question&envId=2023-10-15
        vector<vector<int>> dp(steps + 1, vector<int> (steps / 2 + 1, -1));
        return solve(dp, arrLen, 0, steps);
    }
};