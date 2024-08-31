class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        // using bottom-up DP
        // time complexity: O(M * N), space complexity: O(N), where M == points.size() and N == points[0].size()
        // reference: https://leetcode.com/problems/maximum-number-of-points-with-cost/solutions/1344888/c-dp-from-o-m-n-n-to-o-m-n/?envType=daily-question&envId=2024-08-17
        int m = points.size(), n = points[0].size();
        vector<long long> dp(n, 0);
        for(int j = 0; j < n; j++){
            dp[j] = points[0][j];
        }
        for(int i = 1; i < m; i++){
            vector<long long> left_dp(n, 0), right_dp(n, 0);
            left_dp[0] = dp[0];
            for(int j = 1; j < n; j++){
                left_dp[j] = max(left_dp[j - 1], dp[j] + j);
            }
            right_dp[n - 1] = dp[n - 1] - (n - 1);
            for(int j = n - 2; j >= 0; j--){
                right_dp[j] = max(right_dp[j + 1], dp[j] - j);
            }
            for(int k = 0; k < n; k++){
                dp[k] = points[i][k] + max(left_dp[k] - k, right_dp[k] + k);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};