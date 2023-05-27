class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // dp[l][r] means the value that the player who does the first take (could be either player A or B) can win over another player when focus on nums[l] ~ nums[r]
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        dp[0][0] = nums[0];
        for(int i = 1; i < n; i++){
            for(int j = i; j >= 0; j--){
                dp[j][i] = max(nums[j] - dp[j + 1][i], nums[i] - dp[j][i - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};