class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // using Dijkstra's Algorithm
        vector<vector<pair<int, int>>> next(n);
        vector<int> stop(n, INT_MAX); // stands for the minimum stops of city i which has been visited (to avoid TLE)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // {cost, {to, # of stops}}
        for(vector<int>& flight: flights){
            next[flight[0]].push_back({flight[1], flight[2]});
        }
        pq.push({0, {src, 0}});
        while(!pq.empty()){
            int cost = pq.top().first, to = pq.top().second.first, stops = pq.top().second.second;
            pq.pop();
            if(to == dst)
                return cost;
            if(stops >= stop[to])
                continue;
            stop[to] = stops;
            if(stops == k + 1)
                continue;
            for(pair<int, int>& v: next[to]){
                pq.push({cost + v.second, {v.first, stops + 1}});
            }
        }
        return -1;
    }
};