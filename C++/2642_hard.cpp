class Graph {
public:
    int n;
    vector<vector<pair<int, int>>> graph;
    Graph(int n, vector<vector<int>>& edges) {
        graph = vector<vector<pair<int, int>>> (n);
        this->n = n;
        for(vector<int>& edge: edges){
            addEdge(edge);
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
        return;
    }
    
    int shortestPath(int node1, int node2) {
        // using Dijkstra's Algorithm
        // reference: https://leetcode.com/problems/design-graph-with-shortest-path-calculator/solutions/4274432/dijkstra-s-algorithm-explained-intuition/?envType=daily-question&envId=2023-11-11
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node1});
        dist[node1] = 0;
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            if(p.second == node2)
                return p.first;
            for(pair<int, int> neighbor: graph[p.second]){
                if(p.first + neighbor.second < dist[neighbor.first]){
                    dist[neighbor.first] = p.first + neighbor.second;
                    pq.push({dist[neighbor.first], neighbor.first});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */