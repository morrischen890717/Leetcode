class Solution {
public:
    int knightDialer(int n) {
        // using bottom-up DP
        // time complexity: O(N), space complexity: O(1)
        const int MOD = 1e9 + 7;
        vector<vector<int>> jump = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        // DP method below is to implement dialing from the last digit to the first digit
        vector<int> dp(10, 1);
        for(int i = 0; i < n - 1; i++){
            vector<int> tmp(10, 0);
            for(int j = 0; j < 10; j++){
                for(int next: jump[j]){
                    tmp[next] += dp[j];
                    tmp[next] %= MOD;
                }
            }
            dp = tmp;
        }
        int ans = 0;
        for(int i = 0; i < 10; i++){
            ans += dp[i];
            ans %= MOD;
        }
        return ans;
    }
};