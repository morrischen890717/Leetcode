class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // using Bellman-Ford Algorithm
        // time complexity: O(V * E), V: # of nodes, E: # of edges
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        for(int i = 0; i < n; i++){
            for(vector<int>& edge: times){
                if(dist[edge[0]] != INT_MAX)
                    dist[edge[1]] = min(dist[edge[1]], dist[edge[0]] + edge[2]);
            }
        }
        int maxCost = 0;
        for(int i = 1; i <= n; i++){
            maxCost = max(maxCost, dist[i]);
        }
        return maxCost == INT_MAX ? -1 : maxCost;
    }
};