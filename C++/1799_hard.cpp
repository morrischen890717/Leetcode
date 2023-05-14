class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>& dp, int size, int i, int mask){
        if(i > size / 2)
            return 0;
        if(dp[i][mask] != -1)
            return dp[i][mask];
        for(int j = 0; j < size; j++){
            for(int k = j + 1; k < size; k++){
                int cur_mask = (1 << j) | (1 << k);
                if((mask & cur_mask) == 0)
                    dp[i][mask] = max(dp[i][mask], i * gcd(nums[j], nums[k]) + solve(nums, dp, size, i + 1, mask | cur_mask));
            }
        }
        return dp[i][mask];
    }
    int maxScore(vector<int>& nums) {
        /*
        using top-down DP and bitmask
        reference: https://leetcode.com/problems/maximize-score-after-n-operations/solutions/1118778/c-java-python-bitmask-dp/
        */
        int n = nums.size() / 2;
        vector<vector<int>> dp(n + 1, vector<int> (pow(2, 2 * n), -1));
        return solve(nums, dp, 2 * n, 1, 0);
    }
};