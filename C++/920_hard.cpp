class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        // using bottom-up DP
        // main idea: dp[i][j] denotes the solution of i songs(goal) with j different songs(n).
        // reference: https://leetcode.com/problems/number-of-music-playlists/solutions/180338/dp-solution-that-is-easy-to-understand/
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(goal + 1, vector<long long> (n + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= goal; i++){
            for(int j = 1; j <= n; j++){
                if(j > k)
                    dp[i][j] = (dp[i - 1][j - 1] * j % MOD + dp[i - 1][j] * (j - k) % MOD) % MOD; // (j-k) is because we can not use the songs from (j-1-k-1)-th ~ (j-1)-th in the last song (j-th song)
                else
                    dp[i][j] = dp[i - 1][j - 1] * j % MOD;
            }
        }
        return (int)dp[goal][n];
    }
};