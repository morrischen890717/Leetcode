class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // using BFS
        vector<vector<pair<int, int>>> graph(n);
        for(vector<int>& flight: flights){
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        queue<pair<int, int>> q;
        q.push({0 ,src});
        vector<int> cost(n, INT_MAX);
        while(k >= 0){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int d = q.front().first, id = q.front().second;
                q.pop();
                for(pair<int, int> p: graph[id]){
                    if(d + p.second < cost[p.first]){
                        cost[p.first] = d + p.second;
                        q.push({cost[p.first], p.first});
                    }
                }
            }
            k--;
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};