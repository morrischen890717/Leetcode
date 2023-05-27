class Solution {
public:
    int solve(vector<int>& nums, int n, vector<vector<int>>& dp, int l, int r){
        if(!(l <= r))
            return 0;
        if(dp[l][r] != INT_MIN)
            return dp[l][r];
        dp[l][r] = max(nums[l] - solve(nums, n, dp, l + 1, r), nums[r] - solve(nums, n, dp, l, r - 1)); // similar to Problem 1406 (Stone Game III): https://leetcode.com/problems/stone-game-iii/
        return dp[l][r];
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // dp[l][r] means the value that the player who does the first take (could be either player A or B) can win over another player when focus on nums[l] ~ nums[r]
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, INT_MIN));
        int l = 0, r = n - 1;
        return (solve(nums, n, dp, l, r) >= 0 ? true : false);
    }
};