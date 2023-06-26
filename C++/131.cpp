class Solution {
public:
    void dfs(string &s,  vector<vector<bool>> &dp, vector<string> &cur, int i, vector<vector<string>> &ans){
        if(i == s.length()){
            ans.push_back(cur);
            return;
        }
        for(int j = i; j < s.length(); j++){
            if(dp[i][j]){
                cur.push_back(s.substr(i, j - i + 1));
                dfs(s, dp, cur, j + 1, ans);
                cur.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        /*
        using DP + DFS
        time complexity: O(N * 2^N)
        */
        int len = s.length();
        vector<vector<string>> ans;
        vector<string> cur;
        vector<vector<bool>> dp(len, vector<bool> (len, false)); // dp[i][j] = true if and only if s[i][j] is palindrome
        for(int j = 0; j < len; j++){
            for(int i = 0; i <= j; i++){
                if(s[i] == s[j] && (i + 1 > j - 1 || dp[i + 1][j - 1]))
                    dp[i][j] = true;
            }
        }
        dfs(s, dp, cur, 0, ans);
        return ans;
    }
};