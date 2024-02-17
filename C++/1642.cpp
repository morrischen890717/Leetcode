class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // using priority_queue and Greedy
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1; i < n; i++){
            int diff = heights[i] - heights[i - 1];
            if(diff <= 0)
                continue;
            if(pq.size() < ladders)
                pq.push(diff);
            else if(!pq.empty() && diff > pq.top()){
                bricks -= pq.top();
                pq.pop();
                pq.push(diff);
            }
            else
                bricks -= diff;
            if(bricks < 0)
                return i - 1;
        }
        return n - 1;
    }
};