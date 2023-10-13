class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // using bottom-up DP
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/greatest-sum-divisible-by-three/solutions/431077/java-c-python-one-pass-o-1-space/
        int n = nums.size();
        vector<int> dp(3, 0);
        for(int num: nums){
            vector<int> tmp(dp);
            for(int max_sum: dp){
                tmp[(max_sum + num) % 3] = max(tmp[(max_sum + num) % 3], max_sum + num);
            }
            dp = tmp;
        }
        return dp[0];
    }
};