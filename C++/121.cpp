class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int min_price = 1e6;
        for(int i = 0; i < n; i++){
            int cur_profit = prices[i] - min_price;
            max_profit = max(max_profit, cur_profit);
            min_price = min(min_price, prices[i]);
        }
        return max_profit;
    }
};