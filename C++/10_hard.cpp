class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length(), len2 = p.length();
        vector<vector<bool>> dp(len1 + 1, vector<bool> (len2 + 1, false));
        dp[0][0] = true;
        for(int j = 1; j <= len2; j++){
            if(p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2]; // zero
        }
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(p[j - 1] == '.' || s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*'){
                    dp[i][j] = dp[i][j - 2] || dp[i][j - 1]; // zero || one
                    if(p[j - 2] == '.' || s[i - 1] == p[j - 2])
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // more than one
                }
            }
        }
        return dp[len1][len2];
    }
};