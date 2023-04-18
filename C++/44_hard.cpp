class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = p.length(), len2 = s.length();
        vector<vector<bool>> dp(len1 + 1, vector<bool> (len2 + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= len1; i++){
            if(p[i - 1] != '*')
                break;
            dp[i][0] = true;
        }
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(p[i - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else if((s[j - 1] == p[i - 1] || p[i - 1] == '?') && dp[i - 1][j - 1])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        }
        return dp[len1][len2];
    }
};