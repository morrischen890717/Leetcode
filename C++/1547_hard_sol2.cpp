class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        /*
        using bottom-up DP
        reference: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/solutions/780880/dp-with-picture-burst-balloons/
        */
        cuts.push_back(0);
        cuts.push_back(n);
        int num = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(num, vector<int> (num, 1e7));
        for(int i = 0; i < num - 1; i++){
            dp[i][i + 1] = 0; // there is no cut between cuts[i] ans cuts[j]
        }
        for(int i = num - 1; i >= 0; i--){
            for(int j = i + 1; j < num; j++){
                for(int k = i + 1; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return dp[0][num - 1];
    }
};