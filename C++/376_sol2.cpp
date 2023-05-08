class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int id, int smaller){
        if(dp[id] != -1)
            return dp[id];
        dp[id] = 1;
        for(int i = id - 1; i >= 0; i--){
            if((smaller == 1 || smaller == -1) && nums[i] < nums[id])
                dp[id] = max(dp[id], solve(nums, dp, i, 0) + 1);
            else if((smaller == 0 || smaller == -1) && nums[i] > nums[id])
                dp[id] = max(dp[id], solve(nums, dp, i, 1) + 1);
        }
        return dp[id];
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, dp, n - 1, -1);
    }
};