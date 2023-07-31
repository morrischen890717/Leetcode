class Solution {
public:
    double solve(vector<int>& nums, vector<vector<double>>& dp, int cur, int k){
        if(dp[cur][k] != 0)
            return dp[cur][k];
        double sum = 0;
        for(int i = cur - 1; i > 0; i--){
            sum += nums[i];
            dp[cur][k] = max(dp[cur][k], solve(nums, dp, i, k - 1) + sum / (cur - i));
        }
        return dp[cur][k];
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        // using top-down DP
        // reference: https://leetcode.com/problems/largest-sum-of-averages/solutions/122739/c-java-python-easy-understood-solution-with-explanation/
        int n = nums.size();
        vector<vector<double>> dp(n + 1, vector<double> (k + 1, 0));
        double sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            dp[i + 1][1] = sum / (i + 1);
        }
        return solve(nums, dp, n, k);
    }
};