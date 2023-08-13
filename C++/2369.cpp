class Solution {
public:
    bool validPartition(vector<int>& nums) {
        // using bottom-up DP
        // time complexity: O(N), space complexity: O(N)
        int n = nums.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            int j = i - 1;
            if(j >= 1 && nums[j] == nums[j - 1]){
                if(j >= 2 && nums[j] == nums[j - 2])
                    dp[i] = dp[i - 2] || dp[i - 3];
                else
                    dp[i] = dp[i - 2];
            }
            else if(j >= 2 && nums[j] == nums[j - 1] + 1 && nums[j - 1] == nums[j - 2] + 1)
                dp[i] = dp[i - 3];
        }
        return dp[n];
    }
};