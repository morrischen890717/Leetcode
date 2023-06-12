class Solution {
public:
    string longestPalindrome(string s) {
        /*
        using DP
        time complexity: O(N^2)
        space complexity: O(N^2)
        */
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool> (len, false));
        pair<int, int> ans = {0, 1}; // ans = {start_id, length}
        for(int i = 0; i < len; i++){
            dp[i][i] = true;
            for(int j = 0; j < i; j++){
                if(s[i] == s[j] && (j == i - 1 || dp[j + 1][i - 1])){
                    dp[j][i] = true;
                    if(i - j + 1 > ans.second)
                        ans = {j, i - j + 1};
                }
            }
        }
        return s.substr(ans.first, ans.second);
    }
};