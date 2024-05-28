class Solution {
public:
    int dfs(vector<string>& words, vector<int>& cnt, vector<int>& score, vector<int>& dp, int state){
        if(dp[state] != -1)
            return dp[state];
        dp[state] = 0;
        for(int i = 0; i < words.size(); i++){
            if(state & (1 << i))
                continue;
            vector<int> tmp(cnt.begin(), cnt.end());
            bool valid = true;
            int sum = 0;
            for(char c: words[i]){
                tmp[c - 'a']--;
                sum += score[c - 'a'];
                if(tmp[c - 'a'] < 0){
                    valid = false;
                    break;
                }
            }
            if(!valid)
                continue;
            dp[state] = max(dp[state], sum + dfs(words, tmp, score, dp, state | (1 << i)));
        }
        return dp[state];
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<int> dp(1 << n, -1);
        vector<int> cnt(26, 0);
        for(char letter: letters){
            cnt[letter - 'a']++;
        }
        return dfs(words, cnt, score, dp, 0);
    }
};