class Solution {
public:
    int countBalancedPermutations(string num) {
        // using bottom-up DP
        // reference: https://leetcode.com/problems/count-number-of-balanced-permutations/solutions/6726791/dp-combinatorics-step-by-step-with-images-example-walkthrough-c-python-java/?envType=daily-question&envId=2025-05-09
        const int MOD = 1e9 + 7;
        int len = num.length();
        int sum = 0;
        for(char c: num){
            sum += c - '0';
        }
        if(sum % 2)
            return 0;
        vector<long long> fact(len + 1, 1), inv(len + 1, 1), invFact(len + 1, 1);
        for(int i = 1; i <= len; i++){
            fact[i] = fact[i - 1] * i % MOD;
            if(i >= 2)
                inv[i] = MOD - (MOD / i * inv[MOD % i]) % MOD;
            invFact[i] = invFact[i - 1] * inv[i] % MOD;
        }
        int halfSum = sum / 2, halfLen = len / 2;
        vector<vector<int>> dp(halfSum + 1, vector<int> (halfLen + 1, 0));
        dp[0][0] = 1;
        vector<int> cnt(10, 0);
        for(char c: num){
            int digit = c - '0';
            cnt[digit]++;
            for(int i = halfSum; i >= digit; i--){
                for(int j = halfLen; j >= 1; j--){
                    dp[i][j] += dp[i - digit][j - 1];
                    dp[i][j] %= MOD;
                }
            }
        }
        long long ans = dp[halfSum][halfLen];
        ans = ans * fact[halfLen] % MOD * fact[len - halfLen] % MOD;
        for(int d: cnt){
            ans *= invFact[d];
            ans %= MOD;
        }
        return ans;
    }
};