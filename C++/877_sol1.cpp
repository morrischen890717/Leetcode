class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // using bottom-up DP
        // time complexity: O(N^2), space complexity: O(N^2)
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n, 0)); // dp[i][j] means that the difference of Alice and Bob from piles[i] ~ piles[j]
        for(int j = 0; j < n; j++){
            for(int i = j - 1; i >= 0; i--){
                if((j - i) % 2)
                    dp[i][j] = max(piles[i] + dp[i + 1][j], piles[j] + dp[i][j - 1]);
                else
                    dp[i][j] = min(-piles[i] + dp[i + 1][j], -piles[j] + dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
};