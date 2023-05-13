class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(high + 1, 0);
        dp[0] = 1;
        long long ans = 0;
        for(int i = 0; i <= high; i++){
            if(i + zero <= high){
                dp[i + zero] += dp[i];
                dp[i + zero] %= MOD;
            }
            if(i + one <= high){
                dp[i + one] += dp[i];
                dp[i + one] %= MOD;
            }
        }
        for(int i = low; i <= high; i++){
            ans += dp[i];
            ans %= MOD;
        }
        return ans;
    }
};