class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // using Dijkstra's Algorithm
        vector<vector<pair<int, int>>> transfer(n + 1); // transfer[from] = {weight, to}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < times.size(); i++){
            transfer[times[i][0]].push_back({times[i][2], times[i][1]});
        }
        for(int i = 0; i < transfer[k].size(); i++){
            pq.push(transfer[k][i]);
        }
        vector<bool> visited(n + 1, false);
        visited[k] = true;
        int visitedCnt = 1;
        int maxTime = 0;
        while(!pq.empty() && visitedCnt < n){
            pair<int, int> p = pq.top();
            pq.pop();
            int cost = p.first, to = p.second;
            if(visited[to])
                continue;
            visited[to] = true;
            visitedCnt++;
            maxTime = max(maxTime, cost);
            for(pair<int, int> next: transfer[to]){
                if(!visited[next.second])
                    pq.push({next.first + cost, next.second}); // the weight will be the total weight from source node to the current node
            }
        }
        return visitedCnt == n ? maxTime : -1;
    }
};