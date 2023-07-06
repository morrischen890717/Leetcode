class Solution {
public:
    int find(vector<int>& parent, int i){
        return parent[i] == i ? i : find(parent, parent[i]);
    }
    
    bool uni(vector<int>& parent, vector<int>& rank, int i, int j){
        int root_i = find(parent, i), root_j = find(parent, j);
        if(root_i == root_j) // already in the same connected component
            return false;
        if(rank[root_i] < rank[root_j]){
            parent[root_i] = root_j;
            rank[root_j]++;
        }
        else{
            parent[root_j] = root_i;
            rank[root_i]++;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /*
        using Union-Find (union by rank)
        time complexity: O(N)
        */
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
        for(vector<int>& edge: edges){
            if(!uni(parent, rank, edge[0], edge[1]))
                return edge;
        }
        return {-1, -1};
    }
};