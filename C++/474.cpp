class Solution {
public:
    int count(string s, char c){
        int cnt = 0;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(s[i] == c)
                cnt++;
        }
        return cnt;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(int i = 0; i < len; i++){
            int zero = count(strs[i], '0'), one = count(strs[i], '1');
            for(int j = m; j >= zero; j--){
                for(int k = n; k >= one; k--){
                    dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1);
                }
            }
        }
        return dp[m][n];
    }
};