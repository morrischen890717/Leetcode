class Solution {
public:
    int solve(vector<int>& piles, int n, vector<vector<int>>& dp, int i, int m){
        if(i >= n)
            return 0;
        if(dp[i][m] != INT_MIN)
            return dp[i][m];
        int sum = 0;
        for(int j = i; j < i + 2 * m && j < n; j++){
            sum += piles[j];
            dp[i][m] = max(dp[i][m], sum - solve(piles, n, dp, j + 1, max(m, j - i + 1)));
        }
        return dp[i][m];
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int m = 1;
        int total = 0;
        /*
        dp[i][m] means the number of stones that person (could be either Alice or Bob) 
        who does the first take from index i in condition m can win over another person
        */
        vector<vector<int>> dp(n, vector<int> (100, INT_MIN)); 
        for(int i = 0; i < n; i++){
            total += piles[i];
        }
        return (total + solve(piles, n, dp, 0, 1)) / 2;
        /*
        solve(...) means dp[0], which is the number (Alice's stones - Bob's stones), 
        so if we can have (total + dp[0]) / 2 = ((A's + B's) + (A's - B's)) / 2 = (2 * A's) / 2 = A's
        */
    }
};