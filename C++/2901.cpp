class Solution {
public:
    bool hamming(string& s1, string& s2){
        if(s1.length() != s2.length())
            return false;
        int len = s1.length();
        int d = 0;
        for(int i = 0; i < len; i++){
            if(s1[i] != s2[i])
                d++;
            if(d > 1)
                return false;
        }
        return d == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        int end = 0, len = 1;
        vector<pair<int, int>> dp(n, {1, -1});
        for(int i = 0; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(groups[i] != groups[j] && hamming(words[i], words[j]) && dp[j].first + 1 > dp[i].first)
                    dp[i] = {dp[j].first + 1, j};
                if(dp[i].first > len){
                    len = dp[i].first;
                    end = i;
                }
            }
        }
        vector<string> ans(len);
        for(int i = len - 1; i >= 0; i--, end = dp[end].second){
            ans[i] = words[end];
        }
        return ans;
    }
};