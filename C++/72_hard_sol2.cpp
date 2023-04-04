class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(2, vector<int> (len2 + 1, 1000));
        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = 0;
                else if(i == 0)
                    dp[i][j] = dp[i][j - 1] + 1;
                else if(j == 0)
                    dp[i % 2][j] = dp[(i - 1) % 2][j] + 1;
                else if(word1[i - 1] == word2[j - 1])
                    dp[i % 2][j] = min({dp[(i - 1) % 2][j - 1], dp[(i - 1) % 2][j] + 1, dp[i % 2][j - 1] + 1});
                else
                    dp[i % 2][j] = min({dp[(i - 1) % 2][j - 1] + 1, dp[(i - 1) % 2][j] + 1, dp[i % 2][j - 1] + 1});
            }
        }
        return dp[len1 % 2][len2];
    }
};