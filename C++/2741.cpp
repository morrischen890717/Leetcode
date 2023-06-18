class Solution {
public:
    int dfs(vector<int>&nums, vector<vector<int>>& dp, int prev, int size, int mask){ // prev stands for the last id of current permutation
        if(size == nums.size())
            return 1;
        if(dp[prev + 1][mask] != -1)
            return dp[prev + 1][mask];
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if((mask & (1 << i)) != 0)
                continue;
            if(prev == -1 || nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0){
                res += dfs(nums, dp, i, size + 1, (mask | (1 << i)));
                res %= (int)(1e9 + 7);
            }
        }
        return dp[prev + 1][mask] = res;
    }
    int specialPerm(vector<int>& nums) {
        /*
        using top-down DP with bitmask
        reference: https://leetcode.com/problems/special-permutations/solutions/3650420/beginner-friendly-bit-mask-simple-code/
        */
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (1 << 14, -1));
        return dfs(nums, dp, -1, 0, 0);
    }
};