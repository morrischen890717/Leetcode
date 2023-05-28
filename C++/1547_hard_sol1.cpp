class Solution {
public:
    int dfs(vector<int>& cuts, vector<vector<int>>& dp, int i, int j){
        if(i == j - 1) // there is no cut between cuts[i] and cuts[j]
            return 0;
        if(dp[i][j] != INT_MAX)
            return dp[i][j];
        for(int k = i + 1; k < j; k++){
            dp[i][j] = min(dp[i][j], dfs(cuts, dp, i, k) + dfs(cuts, dp, k, j) + cuts[j] - cuts[i]);
        }
        return dp[i][j];
    }
    int minCost(int n, vector<int>& cuts) {
        /*
        using top-down DP
        reference: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/solutions/780880/dp-with-picture-burst-balloons/
        */
        cuts.push_back(0);
        cuts.push_back(n);
        int num = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(num, vector<int> (num, INT_MAX));
        return dfs(cuts, dp, 0, num - 1);
    }
};