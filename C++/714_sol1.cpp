class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // using Greedy
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108867/c-concise-solution-o-n-time-o-1-space/
        //            https://imgur.com/JZTw2UE
        int hold = -prices[0] - fee, empty = 0;
        for(int price: prices){
            empty = max(empty, hold + price);
            hold = max(hold, empty - price - fee);
        }
        return empty;
    }
};