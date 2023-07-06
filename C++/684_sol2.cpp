class Solution {
public:
    int find(vector<int>& parent, int i){
        return parent[i] == i ? i : find(parent, parent[i]);
    }
    
    bool uni(vector<int>& parent, vector<int>& size, int i, int j){
        int root_i = find(parent, i), root_j = find(parent, j);
        if(root_i == root_j) // two nodes are already in the same connected component, the edge will result in a cycle
            return false;
        if(size[root_i] < size[root_j]){
            parent[root_i] = root_j;
            size[root_j] += size[root_i];
        }
        else{
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /*
        using Union-Find (union by size)
        time complexity: O(N)
        */
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> size(n + 1, 1);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
        for(vector<int>& edge: edges){
            if(!uni(parent, size, edge[0], edge[1]))
                return edge;
        }
        return {-1, -1};
    }
};