class Solution {
public:
    bool solve(vector<int>& nums, int n, vector<int>& dp, int state, int sum, int target, int k){
        if(sum == target){
            k--;
            sum = 0;
        }
        if(dp[state] != 0)
            return dp[state] == 1;
        for(int i = 0; i < n; i++){
            if(state & (1 << i) || sum + nums[i] > target)
                continue;
            if(solve(nums, n, dp, state | (1 << i), sum + nums[i], target, k)){
                dp[state] = 1;
                return true;
            }
        }
        dp[state] = -1;
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // using top-down DP and bitmask
        int n = nums.size();
        vector<int> dp(1 << n, 0);
        dp[(1 << n) - 1] = true;
        int sum = 0;
        for(int num: nums){
            sum += num;
        }
        if(sum % k)
            return false;
        int target = sum / k;
        return solve(nums, n, dp, 0, 0, target, k);
    }
};