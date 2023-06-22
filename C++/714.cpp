class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        /*
        using bottom-up DP
        time complexity: O(N), space complexity: O(N)
        reference:
        https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems/
        https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108871/2-solutions-2-states-dp-solutions-clear-explanation/
        */
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2));
        /*
        dp[i][0] stands for there is 0 stock at the end of i-th day
        dp[i][1] stands for there is 1 stock at the end of i-th day
        */
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee); // do nothing or sell stock
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // do nothing or buy stock
        }
        return dp[n - 1][0];
    }
};