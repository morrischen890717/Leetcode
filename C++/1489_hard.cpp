class Solution {
public:
    int find(vector<int>& parent, int i){
        return parent[i] == i ? i : find(parent, parent[i]);
    }
    void uni(vector<int>& parent, vector<int>& rank, int parentI, int parentJ){
        if(rank[parentI] < rank[parentJ]){
            parent[parentI] = parentJ;
            rank[parentJ]++;
        }
        else{
            parent[parentJ] = parentI;
            rank[parentI]++;
        }
        return;
    }
    int buildMST(int n, vector<vector<int>>& edges, int blockEdge, int addEdge){
        vector<int> parent(n), rank(n, 0);
        // using Union-Find to implement Kruskal's Algorithm
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        int weight = 0;
        if(addEdge != -1){
            int parentI = find(parent, edges[addEdge][0]), parentJ = find(parent, edges[addEdge][1]);
            uni(parent, rank, parentI, parentJ);
            weight += edges[addEdge][2];
        }
        for(int i = 0; i < edges.size(); i++){
            if(i == blockEdge) // we do not use blockEdge
                continue;
            int parentI = find(parent, edges[i][0]), parentJ = find(parent, edges[i][1]);
            if(parentI != parentJ){
                uni(parent, rank, parentI, parentJ);
                weight += edges[i][2];
            }
        }
        int root = find(parent, 0);
        for(int i = 1; i < n; i++){ // cannot construct MST
            if(find(parent, i) != root)
                return INT_MAX;
        }
        return weight;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // using Union-Find(union by rank), Kruskal's Algorithm, and self-defined sort()
        // reference: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/solutions/697761/c-solution-enumerating-edges-with-explanation/
        vector<int> critical, pseudoCritical;
        for(int i = 0; i < edges.size(); i++){
            edges[i].push_back(i); // record its id
        }
        // sorting based on edges' weights
        sort(edges.begin(), edges.end(), [&](vector<int> edge1, vector<int> edge2){
            return edge1[2] < edge2[2];
        });
        int originMST = buildMST(n, edges, -1, -1);
        for(int i = 0; i < edges.size(); i++){
            if(originMST < buildMST(n, edges, i, -1))
                critical.push_back(edges[i][3]);
            else if(originMST == buildMST(n, edges, -1, i))
                pseudoCritical.push_back(edges[i][3]);
        }
        return {critical, pseudoCritical};
    }
};