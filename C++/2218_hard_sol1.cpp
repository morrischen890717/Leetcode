class Solution {
public:
    int f(vector<vector<int>>& piles, vector<vector<int>>& dp, int id, int k){
        if(dp[id][k] > 0)
            return dp[id][k];
        if(id <= 0 || k <= 0)
            return 0;
        int m = piles[id - 1].size();
        int max_val = 0;
        int sum = 0;
        for(int i = 0; i <= m && i <= k; i++){
            if(i != 0)
                sum += piles[id - 1][i - 1];
            max_val = max(max_val, f(piles, dp, id - 1, k - i) + sum);
        }
        dp[id][k] = max_val;
        return dp[id][k];
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
        return f(piles, dp, n, k);
    }
};