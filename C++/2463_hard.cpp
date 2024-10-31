class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // using bottom-up DP
        // reference: https://leetcode.com/problems/minimum-total-distance-traveled/solutions/5988652/beats-100-c-dp-tabulation/?envType=daily-question&envId=2024-10-31
        int n = robot.size(), m = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>> (m + 1, vector<long long> (101, 1e12)));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int robot_pos = robot[i], factory_pos = factory[j][0], limit = factory[j][1];
                long long not_take = (j == 0) ? 1e12 : dp[i][j - 1][0];
                dp[i][j][limit] = not_take;
                for(int k = 0; k < limit; k++){
                    long long take = abs(robot_pos - factory_pos) + ((i == 0) ? 0 : dp[i - 1][j][k + 1]);
                    dp[i][j][k] = min(take, not_take);
                }
            }
        }
        return dp[n - 1][m - 1][0];
    }
};