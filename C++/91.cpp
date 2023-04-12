class Solution {
public:
    bool valid(string s){
        if(s[0] != '0' && stoi(s) <= 26 && stoi(s) >= 1)
            return true;
        return false;
    }
    int numDecodings(string s) {
        int len = s.length();
        vector<int> dp(len, 0);
        if(s[0] == '0')
            return 0;
        dp[0] = 1;
        for(int i = 1; i < len; i++){
            if(valid(s.substr(i, 1)))
                dp[i] += dp[i - 1];
            if(valid(s.substr(i - 1, 2)))
                dp[i] += (i == 1 ? 1 : dp[i - 2]);
        }
        return dp[len - 1];
    }
};