class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int MOD = 1e9 + 7;
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            long long num = 0;
            for(int j = i; j >= 1 && j > i - 10; j--){ // becaues 1 <= k <= 10^9, so j > i - 10(at most 10 digits)
                if(s[j - 1] == '0')
                    continue;
                num += pow(10, i - j) * (s[j - 1] - '0');
                if(num <= k){
                    dp[i] += dp[j - 1];
                    dp[i] %= MOD;
                }
                else
                    break;
            }
        }
        return dp[n];
    }
};