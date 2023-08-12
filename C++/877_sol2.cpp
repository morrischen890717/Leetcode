class Solution {
public:
    int dfs(vector<int>& piles, vector<vector<int>>& dp, int i, int j){
        if(i > j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if((j - i) % 2)
            dp[i][j] = max(piles[i] + dfs(piles, dp, i + 1, j), piles[j] + dfs(piles, dp, i, j - 1));
        else
            dp[i][j] = min(-piles[i] + dfs(piles, dp, i + 1, j), -piles[j] + dfs(piles, dp, i, j - 1));
        return dp[i][j];
    }
    bool stoneGame(vector<int>& piles) {
        // using top-down DP
        // time complexity: O(N^2), space complexity: O(N^2)
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n, -1)); // dp[i][j] means that the difference of Alice and Bob from piles[i] ~ piles[j]
        return dfs(piles, dp, 0, n - 1) > 0;
    }
};