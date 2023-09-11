class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // using priority_queue
        // time complexity: O(NlogN), space complexity: O(N)
        int cost = 0;
        int n = costs.size();
        priority_queue<pair<int, int>> pq; // {diff, id}
        for(int i = 0; i < n; i++){
            int diff = abs(costs[i][0] - costs[i][1]);
            pq.push({diff, i});
        }
        int cntA = 0, cntB = 0;
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            int i = p.second;
            if(costs[i][0] < costs[i][1]){
                if(cntA < n / 2){
                    cost += costs[i][0];
                    cntA++;
                }
                else{
                    cost += costs[i][1];
                    cntB++;
                }
            }
            else{
                if(cntB < n / 2){
                    cost += costs[i][1];
                    cntB++;
                }
                else{
                    cost += costs[i][0];
                    cntA++;
                }
            }
        }
        return cost;
    }
};