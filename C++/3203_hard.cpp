class Solution {
public:
    int farthest(vector<vector<int>>& neighbors, int start){
        int n = neighbors.size();
        int res = -1;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();
                visited[cur] = true;
                res = cur;
                for(int next: neighbors[cur]){
                    if(!visited[next])
                        q.push(next);
                }
            }
        }
        return res;
    }
    int diameter(vector<vector<int>>& neighbors){
        int n = neighbors.size();
        int node1 = farthest(neighbors, 0);
        int node2 = farthest(neighbors, node1);
        queue<int> q;
        q.push(node1);
        vector<bool> visited(n, false);
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();
                visited[cur] = true;
                if(cur == node2)
                    return dist;
                for(int next: neighbors[cur]){
                    if(!visited[next])
                        q.push(next);
                }
            }
            dist++;
        }
        return -1;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // using BFS
        // reference: https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/solutions/5389457/python-farthest-of-farthest/?envType=daily-question&envId=2024-12-24
        // the proof of finding the diameter by using two BFS: https://medium.com/@tbadr/tree-diameter-why-does-two-bfs-solution-work-b17ed71d2881
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> neighbors1(n), neighbors2(m);
        for(vector<int>& edge: edges1){
            neighbors1[edge[0]].push_back(edge[1]);
            neighbors1[edge[1]].push_back(edge[0]);
        }
        for(vector<int>& edge: edges2){
            neighbors2[edge[0]].push_back(edge[1]);
            neighbors2[edge[1]].push_back(edge[0]);
        }
        int d1 = diameter(neighbors1), d2 = diameter(neighbors2);
        return max({d1, d2, (d1 + 1) / 2 + 1 + (d2 + 1) / 2});
    }
};