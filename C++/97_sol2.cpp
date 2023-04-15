class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len1 + len2 != len3)
            return false;
        vector<vector<bool>> dp(2, vector<bool> (len2 + 1, false)); // only use O(s2.length) space
        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = true;
                else if(i == 0)
                    dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
                else if(j == 0)
                    dp[i % 2][0] = dp[(i - 1) % 2][0] && s1[i - 1] == s3[i - 1];
                else
                    dp[i % 2][j] = (dp[(i - 1) % 2][j] && s1[i - 1] == s3[i - 1 + j]) || (dp[i % 2][j - 1] && s2[j - 1] == s3[j - 1 + i]);
            }
        }
        return dp[len1 % 2][len2];
    }
};