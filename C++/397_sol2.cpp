class Solution {
public:
    int recursion(long long n, unordered_map<unsigned int, int>& dp){
        if(dp.count(n) > 0)
            return dp[n];
        if(n % 2 == 0)
            return dp[n] = 1 + recursion(n / 2, dp);
        else
            return dp[n] = 1 + min(recursion(n + 1, dp), recursion(n - 1, dp));
    }
    int integerReplacement(int n) {
        unordered_map<unsigned int, int> dp;
        dp[1] = 0;
        return recursion(n, dp);
    }
};