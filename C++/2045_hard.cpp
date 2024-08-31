class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // using Dijkstra's Algorithm
        // time complexity: O((E + V) * logV), space complexity: O(E + V)
        // reference: https://leetcode.com/problems/second-minimum-time-to-reach-destination/solutions/1525149/python-modified-dijkstra-explained/?envType=daily-question&envId=2024-07-28
        vector<vector<int>> graph(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(vector<int>& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        pq.push({0, 1});
        vector<vector<int>> reach(n + 1);
        while(!pq.empty()){
            pair<int, int> cur = pq.top();
            pq.pop();
            for(int next: graph[cur.second]){
                int next_time = (cur.first / change) % 2 ? (cur.first / change + 1) * change + time : cur.first + time;
                if(reach[next].empty() || (reach[next].size() == 1 && next_time != reach[next][0])){
                    reach[next].push_back(next_time);
                    if(next == n && reach[next].size() == 2)
                        return reach[n][1];
                    pq.push({next_time, next});
                }
            }
        }
        return -1;
    }
};