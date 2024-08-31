class Solution {
public:
    void dijkstra(vector<vector<int>>& edges, vector<vector<pair<int, int>>>& graph, vector<vector<int>>& dist, int source, int diff, int run){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        dist[source][run] = 0;
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            int d = p.first, cur = p.second;
            if(d > dist[cur][run])
                continue;
            for(pair<int, int> next: graph[cur]){
                int weight = edges[next.second][2] == -1 ? 1 : edges[next.second][2];
                if(run == 1 && edges[next.second][2] == -1){
                    int newWeight = dist[next.first][0] - dist[cur][1] + diff;
                    if(newWeight > weight)
                        edges[next.second][2] = weight = newWeight;
                }
                if(dist[cur][run] + weight < dist[next.first][run]){
                    dist[next.first][run] = dist[cur][run] + weight;
                    pq.push({dist[next.first][run], next.first});
                }
            }
        }
        return;
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        // using Dijkstra's Algorithm
        // reference: https://leetcode.com/problems/modify-graph-edge-weights/solutions/5708699/dijkstra-s-with-tc-o-e-v-log-v-beats-100-in-all-languages/?envType=daily-question&envId=2024-08-30
        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1], i});
            graph[edges[i][1]].push_back({edges[i][0], i});
        }
        vector<vector<int>> dist(n, vector<int> (2, INT_MAX));
        dijkstra(edges, graph, dist, source, 0, 0);
        int diff = target - dist[destination][0];
        if(diff < 0)
            return {};
        dijkstra(edges, graph, dist, source, diff, 1);
        if(dist[destination][1] < target)
            return {};
        for(vector<int>& edge: edges){
            edge[2] = edge[2] == -1 ? 1 : edge[2];
        }
        return edges;
    }
};