class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(s[i] == s[j])
                    dp[j][i] = dp[j + 1][i - 1];
                else
                    dp[j][i] = min(dp[j][i - 1], dp[j + 1][i]) + 1;
            }
        }
        return dp[0][n - 1];
    }
};