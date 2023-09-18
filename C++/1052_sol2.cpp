class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // using bottom-up DP
        // time complexity: O(N), space complexity: O(minutes)
        int n = customers.size();
        vector<vector<int>> dp(minutes, vector<int> (2, 0));
        int sum = 0; // the sum of the {minutes} consecutive customers
        for(int i = 0; i < n; i++){
            sum += customers[i];
            if(i == 0)
                dp[i][1] = sum;
            else
                dp[i % minutes][1] = max(dp[(i - 1) % minutes][1] + (grumpy[i] ? 0 : customers[i]), dp[i % minutes][0] + sum);
            if(i == 0)
                dp[i % minutes][0] = grumpy[i] ? 0 : customers[i];
            else
                dp[i % minutes][0] = grumpy[i] ? dp[(i - 1) % minutes][0] : dp[(i - 1) % minutes][0] + customers[i];
            if(i + 1 >= minutes)
                sum -= customers[i + 1 - minutes];
        }
        return dp[(n - 1) % minutes][1];
    }
};