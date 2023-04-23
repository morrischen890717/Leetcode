class Solution {
public:
    const int MOD = 1e9 + 7;
    int dfs(string& s, int k, int i, vector<int>& dp){
        if(i == s.length())
            return 1;
        if(s[i] == '0')
            return dp[i] = 0;
        if(dp[i] != -1)
            return dp[i];
        long long num = 0;
        int ans = 0;
        for(int j = i; j < s.length(); j++){
            num = num * 10 + (s[j] - '0');
            if(num > k)
                break;
            else{
                ans += dfs(s, k, j + 1, dp);
                ans %= MOD;
            }
        }
        return dp[i] = ans;
    }
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n, -1);
        return dfs(s, k, 0, dp);
    }
};