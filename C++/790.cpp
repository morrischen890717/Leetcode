class Solution {
public:
    int numTilings(int n) {
        // using bottom-up DP
        // time complexity: O(N), space complexity: O(1)
        if(n == 0 || n == 1)
            return 1;
        else if(n == 2)
            return 2;
        const int MOD = 1e9 + 7;
        vector<int> dp(3, 0);
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        int trimino = 0;
        /*
        e.g. trimino
        dp[i-3]   dp[i-4]  dp[i-5]   dp[i-6]
        111       1111     11221     112211
        111       1221     12211     122221
        */
        for(int i = 3; i <= n; i++){
            trimino += dp[(i - 3) % 3];
            trimino %= MOD;
            // dp[i - 1] stands for one straight domino, dp[i - 2] stands for two horizontal dominos
            dp[i % 3] = (dp[(i - 1) % 3] + (dp[(i - 2) % 3] + (trimino * 2) % MOD) % MOD) % MOD;
        }
        return dp[n % 3];
    }
};