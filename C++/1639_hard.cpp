class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int l = target.length();
        int n = words.size();
        int m = words[0].length();
        vector<int> dp(l + 1, 0);
        vector<vector<int>> cnt(m, vector<int> (26, 0));
        const int mod = pow(10, 9) + 7;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cnt[i][words[j][i] - 'a']++;
            }
        }
        dp[0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = l; j >= 1; j--){
                dp[j] += ((long long)dp[j - 1] * cnt[i][target[j - 1] - 'a']) % mod;
                dp[j] %= mod;
            }
        }
        return dp[l];
    }
};