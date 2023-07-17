class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10000;
        vector<int> cnt(n + 1, 0);
        for(int num: nums){
            cnt[num]++;
        }
        vector<int> dp(2, 0);
        dp[1] = cnt[1];
        for(int i = 2; i <= n; i++){
            dp[i % 2] = max(dp[(i - 1) % 2], i * cnt[i] + dp[(i - 2) % 2]);
        }
        return dp[n % 2];
    }
};