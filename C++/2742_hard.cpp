class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // using bottom-up DP
        // time complexity: O(N^2), space complexity: O(N)
        // reference: https://leetcode.com/problems/painting-the-walls/solutions/3650707/java-c-python-7-lines-knapsack-dp/?envType=daily-question&envId=2023-10-14
        // main: This is a Knapsack Problem
        int n = cost.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = n; j > 0; j--){
                dp[j] = min(dp[j], dp[max(0, j - time[i] - 1)] + cost[i]);
            }
        }
        return dp[n];
    }
};