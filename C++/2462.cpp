class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long totalCost = 0;
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int l = 0, r = n - 1;
        while(k > 0){
            while(pq1.size() < candidates && l <= r){
                pq1.push(costs[l]);
                l++;
            }
            while(pq2.size() < candidates && l <= r){
                pq2.push(costs[r]);
                r--;
            }
            int candidate1 = pq1.empty() ? INT_MAX : pq1.top();
            int candidate2 = pq2.empty() ? INT_MAX : pq2.top();
            if(candidate2 < candidate1){
                pq2.pop();
                totalCost += candidate2;
            }
            else{
                pq1.pop();
                totalCost += candidate1;
            }
            k--;
        }
        return totalCost;
    }
};