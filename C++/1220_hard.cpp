class Solution {
public:
    int countVowelPermutation(int n) {
        // using bottom-up DP
        // time complexity: O(N), space complexity: O(1)
        const int MOD = 1e9 + 7;
        vector<int> dp(5, 1);
        for(int i = 1; i < n; i++){
            vector<int> tmp(5, 0);
            tmp[0] = ((dp[1] + dp[2]) % MOD + dp[4]) % MOD;
            tmp[1] = (dp[0] + dp[2]) % MOD;
            tmp[2] = (dp[1] + dp[3]) % MOD;
            tmp[3] = dp[2] % MOD;
            tmp[4] = (dp[2] + dp[3]) % MOD;
            dp = tmp;
        }
        int sum = 0;
        for(int num: dp){
            sum += num;
            sum %= MOD;
        }
        return sum;
    }
};