class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int target){
        if(target < 0)
            return 0;
        if(dp[target] != -1)
            return dp[target];
        dp[target] = 0;
        for(int i = 0; i < nums.size(); i++){
            dp[target] += solve(nums, dp, target - nums[i]);
        }
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        return solve(nums, dp, target);
    }
};