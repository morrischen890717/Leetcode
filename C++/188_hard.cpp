class Solution {
public:
    int recursion(vector<int>& prices, int n, int k, int id, int lock, vector<vector<vector<int>>>& max_profit){
        if(k == 0 || id >= n)
            return 0;
        if(max_profit[id][lock][k] != -1)
            return max_profit[id][lock][k];
        int profit;
        if(!lock){  // can buy
            profit = max(recursion(prices, n, k, id + 1, 0, max_profit), -prices[id] + recursion(prices, n, k, id + 1, 1, max_profit));
        }
        else{       // can sell
            profit = max(recursion(prices, n, k, id + 1, 1, max_profit), prices[id] + recursion(prices, n, k - 1, id, 0, max_profit));
        }
        max_profit[id][lock][k] = profit;
        return max_profit[id][lock][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> max_profit(n, vector<vector<int>> (2, vector<int> (k + 1, -1)));
        return recursion(prices, n, k, 0, 0, max_profit);
    }
};