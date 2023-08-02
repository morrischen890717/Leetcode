class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // using BFS
        unordered_map<int, vector<int>> stations; // {stationId, buses which will pass through this station}
        vector<bool> visited(routes.size(), false); // visited[i] stands for if i-th bus had been visited
        for(int i = 0; i < routes.size(); i++){
            for(int j = 0; j < routes[i].size(); j++){
                stations[routes[i][j]].push_back(i);
            }
        }
        int cnt = 0;
        queue<int> q;
        q.push(source);
        while(!q.empty()){ // BFS
            int size = q.size();
            for(int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();
                if(cur == target)
                    return cnt;
                for(int bus: stations[cur]){ // the buses which will pass through cur-th station
                    if(visited[bus])
                        continue;
                    visited[bus] = true;
                    for(int station: routes[bus])
                        q.push(station);
                }
            }
            cnt++;
        }
        return -1;
    }
};