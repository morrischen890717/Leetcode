class Solution {
public:
    int find(vector<int>& parent, int i){
        return parent[i] == i ? i : find(parent, parent[i]);
    }
    void uni(vector<int>& parent, vector<int>& size, int i, int j){
        int root_i = find(parent, i), root_j = find(parent, j);
        if(root_i == root_j)
            return;
        parent[root_i] = root_j;
        size[root_j] += size[root_i];
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_set<int> s;
        vector<int> parent(n), size(n, 1), cnt(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(vector<int>& edge: edges){
            uni(parent, size, edge[0], edge[1]);
            cnt[edge[0]]++;
            cnt[edge[1]]++;
        }
        for(int i = 0; i < n; i++){
            int root = find(parent, i);
            s.insert(root);
            if(size[root] - 1 != cnt[i]){
                size[root] = -1;
                s.erase(root);
            }
        }
        return s.size();
    }
};