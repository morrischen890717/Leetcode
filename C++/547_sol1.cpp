class Solution {
public:
    int find(vector<int>& parent, int i){
        return parent[i] == i ? i : find(parent, parent[i]);
    }
    void uni(vector<int>& parent, vector<int>& rank, int i, int j){
        int parent_i = find(parent, i), parent_j = find(parent, j);
        if(parent_i == parent_j)
            return;
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        // using Union-Find (union by rank)
        int n = isConnected.size();
        vector<int> parent(n), rank(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j])
                    uni(parent, rank, i, j);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};