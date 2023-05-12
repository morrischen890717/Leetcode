class Solution {
public:
    long long solve(vector<vector<int>>& questions, vector<long long>& dp, int n, int i){
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        dp[i] = max(questions[i][0] + solve(questions, dp, n, i + questions[i][1] + 1), solve(questions, dp, n, i + 1));
        return dp[i];
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return solve(questions, dp, n, 0);
    }
};