class Solution {
public:
    void backtrack(vector<vector<int>>& graph, vector<int>& dist, int cur){
        for(int prev: graph[cur]){
            if(dist[cur] + 1 < dist[prev]){
                dist[prev] = dist[cur] + 1;
                backtrack(graph, dist, prev);
            }
        }
        return;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> dist(n, INT_MAX);
        vector<vector<int>> graph(n);
        dist[n - 1] = 0;
        for(int i = 0; i < n - 1; i++){
            graph[i + 1].push_back(i);
            dist[i] = n - 1 - i;
        }
        for(vector<int>& q: queries){
            int from = q[0], to = q[1];
            graph[to].push_back(from);
            backtrack(graph, dist, to);
            ans.push_back(dist[0]);
        }
        return ans;
    }
};