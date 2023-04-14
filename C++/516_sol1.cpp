class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++){
            for(int j = i; j >= 0; j--){
                if(i == j)
                    dp[i][j] = 1;
                else if(s[i] == s[j])
                    dp[j][i] = dp[j + 1][i - 1] + 2;
                else
                    dp[j][i] = max(dp[j + 1][i], dp[j][i - 1]);
            }
        }
        return dp[0][n - 1];
    }
};