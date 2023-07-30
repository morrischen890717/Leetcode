class Solution {
public:
    int strangePrinter(string s) {
        // using bottom-up DP
        // time complexity: O(N^3), space complexity: O(N^2)
        int len = s.length();
        vector<vector<int>> dp(len, vector<int> (len, 0));
        for(int i = 0; i < len; i++){
            dp[i][i] = 1;
            for(int j = 0; j < i; j++){
                if(s[i] == s[i - 1])
                    dp[j][i] = dp[j][i - 1];
                dp[j][i] = dp[j][i - 1] + 1;
                for(int k = j; k < i; k++){
                    if(s[k] == s[i]){
                        // dp[j][k] + dp[k + 1][i - 1] means that we print s[i] from index in [k, i] first, then print other characters in [k + 1, i - 1]
                        dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i - 1]);
                    }       
                }
            }
        }
        return dp[0][len - 1];
    }
};