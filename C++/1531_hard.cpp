class Solution {
public:
    int encoding(int cnt){
        if(cnt == 1)
            return 0;
        else if(cnt < 10)
            return 1;
        else if(cnt < 100)
            return 2;
        return 3;
    }
    int solve(string& s, vector<vector<int>>& dp, int i, int k){
        if(k < 0)
            return 1e4;
        if(i >= s.length() || s.length() - i <= k)
            return 0;
        if(dp[i][k] != -1)
            return dp[i][k];
        dp[i][k] = 1e4;
        vector<int> cnt(26, 0);
        int max_cnt = 0;
        for(int j = i; j < s.length(); j++){
            max_cnt = max(max_cnt, ++cnt[s[j] - 'a']);
            dp[i][k] = min(dp[i][k], 1 + encoding(max_cnt) + solve(s, dp, j + 1, k - (j - i + 1 - max_cnt)));
        }
        return dp[i][k];
    }
    int getLengthOfOptimalCompression(string s, int k) {
        // using top-down DP
        // reference: https://leetcode.com/problems/string-compression-ii/solutions/756022/c-top-down-dp-with-explanation-64ms-short-and-clear/
        int len = s.length();
        vector<vector<int>> dp(len, vector<int> (k + 1, -1));
        return solve(s, dp, 0, k);
    }
};