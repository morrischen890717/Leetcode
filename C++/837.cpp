class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1, 0.0);
        double p = 1.0 / maxPts;
        dp[0] = 1.0;
        double sum = 0.0;
        for(int i = 0; i <= n && i - maxPts < k; i++){
            dp[i] += p * sum;
            // sliding window
            if(i - maxPts >= 0)
                sum -= dp[i - maxPts];
            if(i < k)
                sum += dp[i];
        }
        double ans = 0.0;
        for(int i = k; i <= n; i++){
            ans += dp[i];
        }
        return ans;
    }
};