class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // using bottom-up DP
        // time complexity: O(N), space complexity: O(1)
        int n = cost.size();
        vector<int> dp(2, 0);
        dp[0] = dp[1] = 0;
        for(int i = 2; i <= n; i++){
            dp[i % 2] = min(dp[(i - 1) % 2] + cost[i - 1], dp[(i - 2) % 2] + cost[i - 2]);
        }
        return dp[n % 2];
    }
};