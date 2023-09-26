class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // using BFS
        vector<int> ans(n, -1);
        vector<vector<vector<int>>> graph(n, vector<vector<int>> (2)); // graph[nodeId][red or blue] = {neighbor of nodeId}
        for(vector<int>& redEdge: redEdges){
            graph[redEdge[0]][0].push_back(redEdge[1]);
        }
        for(vector<int>& blueEdge: blueEdges){
            graph[blueEdge[0]][1].push_back(blueEdge[1]);
        }
        vector<vector<bool>> visited(n, vector<bool> (2, false)); // {nodeId, red or blue}
        queue<pair<int, int>> q; // {nodeId, red or blue(0: red, 1: blue)}
        q.push({0, 0});
        q.push({0, 1});
        visited[0][0] = visited[0][1] = true;
        int len = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> p = q.front();
                q.pop();
                if(ans[p.first] == -1)
                    ans[p.first] = len;
                for(int next: graph[p.first][p.second ^ 1]){
                    if(!visited[next][p.second ^ 1]){
                        visited[next][p.second ^ 1] = true;
                        q.push({next, p.second ^ 1});
                    }
                }
            }
            len++;
        }
        return ans;
    }
};