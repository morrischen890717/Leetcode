class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // using bottom-up DP
        // reference: https://leetcode.com/problems/total-characters-in-string-after-transformations-i/solutions/5973021/java-c-python-dp/?envType=daily-question&envId=2025-05-13
        const int MOD = 1e9 + 7;
        int ans = 0;
        vector<int> dp(100050, 0);
        for(int i = 0; i < 26; i++){
            dp[i] = 1;
        }
        for(int i = 26; i < 100050; i++){
            dp[i] = (dp[i - 26] + dp[i - 26 + 1]) % MOD;
        }
        for(char c: s){
            ans += dp[t + c - 'a'];
            ans %= MOD;
        }
        return ans;
    }
};