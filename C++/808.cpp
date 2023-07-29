class Solution {
public:
    double solve(int soupA, int soupB, vector<vector<double>>& dp){
        if(soupA <= 0 && soupB <= 0)
            return 0.5;
        else if(soupA <= 0)
            return 1.0;
        else if(soupB <= 0)
            return 0.0;
        else if(dp[soupA][soupB] != -1)
            return dp[soupA][soupB];
        return dp[soupA][soupB] = 0.25 * (solve(soupA - 4, soupB, dp) + solve(soupA - 3, soupB - 1, dp) + solve(soupA - 2, soupB - 2, dp) + solve(soupA - 1, soupB - 3, dp));
    }
    double soupServings(int n) {
        // reference: https://leetcode.com/problems/soup-servings/solutions/121711/c-java-python-when-n-4800-just-return-1/
        if(n > 4800)
            return 1.0;
        vector<vector<double>> dp(200, vector<double> (200, -1.0));
        n = n % 25 ? n / 25 + 1 : n / 25;
        return solve(n, n, dp);
    }
};