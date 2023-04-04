class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int smallest;
        int highest;
        int ans = 0;
        vector<int> dp1(n, 0); // dp1 stores the max profit from day 0 to day i
        vector<int> dp2(n, 0); // dp2 stores the max profit from day i to day n-1
        smallest = prices[0];
        for(int i = 1; i < n; i++){
            if(prices[i] < smallest)
                smallest = prices[i];
            dp1[i] = max(dp1[i - 1], prices[i] - smallest);
        }
        highest = prices[n - 1];
        for(int i = n - 2; i >= 0; i--){
            if(prices[i] > highest)
                highest = prices[i];
            dp2[i] = max(dp2[i + 1], highest - prices[i]);
        }
        for(int i = 0; i < n; i++){
            ans = max(ans, dp1[i] + dp2[i]); // add the two transactions (day 0 ~ day i, and day i ~ day n-1)
        }
        return ans;
    }
};