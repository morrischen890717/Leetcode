class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // This problem can be seen as 0/1 Knapsack Problem
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % 2)
            return false;
        sum /= 2; // if we can a subset with sum == (total sum) / 2, then we can partition the array into two subsets with same sum
        vector<vector<bool>> dp(2, vector<bool> (sum + 1, false));
        dp[0][0] = true;
        // dp[i][j] represents whether we can make a subset with sum == j from nums[0] ~ nums[i - 1]
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(j - nums[i - 1] >= 0)
                    dp[i % 2][j] = dp[(i - 1) % 2][j] || dp[(i - 1) % 2][j - nums[i - 1]]; // do not take || take
                else
                    dp[i % 2][j] = dp[(i - 1) % 2][j];
            }
        }
        return dp[n % 2][sum];
    }
};