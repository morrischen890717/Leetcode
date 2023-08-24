class Solution {
public:
    int find(vector<int>& parent, int i){
        return parent[i] == i ? i : find(parent, parent[i]);
    }
    void uni(vector<int>& parent, vector<int>& size, int i, int j){
        int parentI = find(parent, i), parentJ = find(parent, j);
        if(parentI == parentJ)
            return;
        if(size[parentI] < size[parentJ]){
            parent[parentI] = parentJ;
            size[parentJ] += size[parentI];
        }
        else{
            parent[parentJ] = parentI;
            size[parentI] += size[parentJ];
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        // using Union-Find(union by size)
        int ans = 0;
        int n = stones.size();
        vector<int> parent(n), size(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    uni(parent, size, i, j);
            }
        }
        for(int i = 0; i < n; i++){
            if(parent[i] == i) // find root
                ans += size[i] - 1; // remove all expect for root itself
        }
        return ans;
    }
};