class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int mod = pow(10, 9) + 7;
        vector<vector<int>> dp(minProfit + 1, vector<int> (n + 1, 0));
        dp[0][0] = 1;
        for(int k = 0; k < group.size(); k++){
            int g = group[k], p = profit[k];
            for(int i = minProfit; i >= 0; i--){
                for(int j = n - g; j >= 0; j--){
                    int newProfit = min(i + p, minProfit);  // if i + p >= minProfit then set to minProfit(because the profit which >= minProfit are all the same)
                    dp[newProfit][j + g] += dp[i][j];  // dp[i][j] respresent # of schemes before adding k-th group and profit
                    dp[newProfit][j + g] %= mod;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= n; i++){
            ans += dp[minProfit][i];
            ans %= mod;
        }
        return ans;
    }
};