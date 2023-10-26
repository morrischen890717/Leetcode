class Solution {
public:
    int find(vector<int>& parent, int i){
        return i == parent[i] ? i : find(parent, parent[i]);
    }
    void uni(vector<int>& parent, vector<int>& rank, int i, int j){
        int parent_i = find(parent, i), parent_j = find(parent, j);
        if(rank[parent_i] < rank[parent_j]){
            parent[parent_i] = parent_j;
            rank[parent_j]++;
        }
        else{
            parent[parent_j] = parent_i;
            rank[parent_i]++;
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // using Union-Find(union by rank)
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(vector<int>& connection: connections){
            uni(parent, rank, connection[0], connection[1]);
        }
        int connected_component = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == i)
                connected_component++;
        }
        return connections.size() >= n - 1 ? connected_component - 1 : -1;
    }
};