class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        /*
        using Dijkstra's Algorithm
        reference: https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/solutions/3468268/dijkstra-s-algorithm-with-roads-as-edges/
        */
        vector<vector<int>> roads;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dist;
        roads.push_back({start[0], start[1], start[0], start[1], 0});
        dist.push_back(0);
        for(int i = 0; i < specialRoads.size(); i++){
            if(specialRoads[i][4] < abs(specialRoads[i][2] - specialRoads[i][0]) + abs(specialRoads[i][3] - specialRoads[i][1])){
                roads.push_back(specialRoads[i]);
                dist.push_back(INT_MAX);
            }
        }
        pq.push({0, 0});    // {dist, id} means that dist is the distance from starting point to (roads[id][2], roads[id][3])
        while(!pq.empty()){
            vector<int> cur = pq.top(); // every time we take the element which has the minimum distance from starting point
            pq.pop();
            int cur_dist = cur[0], id = cur[1]; // id means the id in vectors roads and dist
            int end_x = roads[id][2], end_y = roads[id][3];
            for(int i = 0; i < roads.size(); i++){  // try every road to let the distance from starting point to each (roads[i][2], roads[i][3]) shorter
                int start_x = roads[i][0], start_y = roads[i][1], cost = roads[i][4];
                if(dist[i] > dist[id] + abs(start_x - end_x) + abs(start_y - end_y) + cost){
                    dist[i] = dist[id] + abs(start_x - end_x) + abs(start_y - end_y) + cost;
                    pq.push({dist[i], i});
                }
            }
        }
        int ans = (target[0] - start[0]) + (target[1] - start[1]);
        for(int i = 0; i < roads.size(); i++){  // go to the target point
            ans = min(ans, dist[i] + abs(target[0] - roads[i][2]) + abs(target[1] - roads[i][3]));
        }
        return ans;
    }
};