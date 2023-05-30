class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
        using bottom-up DP
        reference: https://leetcode.com/problems/coin-change-ii/solutions/99212/knapsack-problem-java-solution-with-thinking-process-o-nm-time-and-o-m-space/
        dp[i][j] : the number of combinations to make up amount j by using the first i types of coins
            1. not using the ith coin, only using the first i-1 coins to make up amount j, then we have dp[i-1][j] ways.
            2. using the ith coin, since we can use unlimited same coin, we need to know 
            how many ways to make up amount j - coins[i-1] by using first i coins(including ith), which is dp[i][j-coins[i-1]]
        And we can turn the 2D vector to 1D vector.
        */
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int coin: coins){
            for(int j = 1; j <= amount; j++){
                dp[j] += (j >= coin ? dp[j - coin] : 0);
            }
        }
        return dp[amount];
    }
};