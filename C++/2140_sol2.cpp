class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; i--){
            int point = questions[i][0];
            int next = min(n, i + questions[i][1] + 1);
            dp[i] = max(point + dp[next], dp[i + 1]);
        }
        return dp[0];
    }
};