class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<vector<string>> dp(n + 1);
        unordered_set<string> ss(wordDict.begin(), wordDict.end());
        string sub_string;
        dp[0] = {""};
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                sub_string = s.substr(j, i - j);
                if(dp[j].size() > 0 && ss.count(sub_string) > 0){ // cut string s into two part (dp[j] & s[j:i])
                    for(int k = 0; k < dp[j].size(); k++){
                        if(j == 0)
                            dp[i].push_back(sub_string);
                        else
                            dp[i].push_back(dp[j][k] + " " + sub_string);
                    }
                }
            }
        }
        return dp[n];
    }
};