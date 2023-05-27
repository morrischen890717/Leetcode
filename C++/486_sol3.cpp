class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        // space: O(N)
        int n = nums.size();
        vector<int> dp(n + 1, 0); // dp[j] means the value that the player who does first take can win over another player from nums[j] ~ nums[i]
        for(int i = 0; i < n; i++){
            for(int j = i; j >= 0; j--){
                dp[j] = max(nums[j] - dp[j + 1], nums[i] - dp[j]);
            }
        }
        return dp[0] >= 0;
    }
};