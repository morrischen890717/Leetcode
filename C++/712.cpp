class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        /*
        using DP
        This problem is similar to Edit Distance.
        Time complexity: O(len1 * len2), Space complexity: O(len2)
        */
        int len1 = s1.length(), len2 = s2.length();
        vector<vector<int>> dp(2, vector<int> (len2 + 1, 0));
        for(int j = 1; j <= len2; j++){
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }
        for(int i = 1; i <= len1; i++){
            dp[i % 2][0] = dp[(i - 1) % 2][0] + s1[i - 1];
            for(int j = 1; j <= len2; j++){
                if(s1[i - 1] == s2[j - 1])
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                else
                    dp[i % 2][j] = min(dp[(i - 1) % 2][j] + s1[i - 1], dp[i % 2][j - 1] + s2[j - 1]);
            }
        }
        return dp[len1 % 2][len2];
    }
};