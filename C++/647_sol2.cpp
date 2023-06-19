class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int ans = 0;
        vector<vector<bool>> dp(len, vector<bool> (len, false));
        for(int i = 0; i < len; i++){
            for(int j = 0; j <= i; j++){
                if(s[j] == s[i] && (j + 1 >= i - 1 || dp[j + 1][i - 1])){
                    dp[j][i] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};