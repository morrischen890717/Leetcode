class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(2, vector<int> (len2 + 1, 0));
        for(int j = 1; j <= len2; j++){
            dp[0][j] = j;
        }
        for(int i = 1; i <= len1; i++){
            dp[i % 2][0] = i;
            for(int j = 1; j <= len2; j++){
                dp[i % 2][j] = (word1[i - 1] == word2[j - 1] ? dp[(i - 1) % 2][j - 1] : min(dp[(i - 1) % 2][j] + 1, dp[i % 2][j - 1] + 1));
            }
        }
        return dp[len1 % 2][len2];
    }
};