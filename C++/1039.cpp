class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        // using bottom-up DP
        // time complexity: O(N^3)
        // reference: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/solutions/286705/java-c-python-dp/
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int j = 2; j < n; j++){
            for(int i = j - 2; i >= 0; i--){
                dp[i][j] = INT_MAX;
                for(int k = i + 1; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
                }
            }
        }
        return dp[0][n - 1];
    }
};