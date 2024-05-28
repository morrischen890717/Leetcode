class Solution {
public:
    vector<string> solve(string s, unordered_set<string>& dict, int i, vector<bool>& visited, vector<vector<string>>& dp){
        if(visited[i])
            return dp[i];
        visited[i] = true;
        for(int j = i; j < s.length(); j++){
            string ss = s.substr(i, j - i + 1);
            if(dict.count(ss)){
                if(j + 1 == s.length()){
                    dp[i].push_back(ss);
                    return dp[i];
                }
                vector<string> v = solve(s, dict, j + 1, visited, dp);
                if(!v.empty()){
                    for(string& w: v){
                        dp[i].push_back(ss + " " + w);
                    }
                }
            }
        }
        return dp[i];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<vector<string>> dp(len);
        vector<bool> visited(len, false);
        unordered_set<string> dict;
        for(string& word: wordDict){
            dict.insert(word);
        }
        return solve(s, dict, 0, visited, dp);
    }
};