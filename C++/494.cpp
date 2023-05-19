class Solution {
public:
    int subsetPositiveSum(vector<int>& nums, int target){
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = target; j - nums[i] >= 0; j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
        reference: https://leetcode.com/problems/target-sum/solutions/97334/java-15-ms-c-3-ms-o-ns-iterative-dp-solution-using-subset-sum-with-explanation/
        */
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum < abs(target) || (target + sum) % 2)
            return 0;
        target = (target + sum) / 2;
        return subsetPositiveSum(nums, target);
    }
};