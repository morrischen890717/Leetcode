class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        /*
        using DP + bitmask
        time complexity: O(N * 2^N)
        space complexity: O(2^N)
        reference: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/solutions/335668/dp-with-bit-masking-solution-best-for-interviews/
        The logic of "nums[j] <= (target - (sum[i] % target))": https://imgur.com/a/1hqMiCG
        */
        int n = nums.size();
        vector<bool> dp(1 << n, false);
        vector<int> sum(1 << n, 0);
        int target = 0;
        for(int num: nums){
            target += num;
        }
        if(target % k)
            return false;
        target /= k;
        sort(nums.begin(), nums.end());
        if(nums.back() > target)
            return false;
        dp[0] = true;
        for(int i = 0; i < (1 << n); i++){
            if(dp[i]){
                for(int j = 0; j < n; j++){
                    int state = i | (1 << j);
                    if(state != i){
                        if(nums[j] <= (target - (sum[i] % target))){
                            dp[state] = true;
                            sum[state] = sum[i] + nums[j];
                        }
                        else
                            break;
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};