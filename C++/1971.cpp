class Solution {
public:
    int find(vector<int>& parent, int i){
        return i == parent[i] ? i : find(parent, parent[i]);
    }
    void uni(vector<int>& parent, int i, int j){
        int parent_i = find(parent, i), parent_j = find(parent, j);
        if(parent_i == parent_j)
            return;
        parent[parent_i] = parent_j;
        return;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(vector<int>& edge: edges){
            uni(parent, edge[0], edge[1]);
        }
        return find(parent, source) == find(parent, destination);
    }
};