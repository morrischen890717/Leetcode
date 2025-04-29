class Solution {
public:
    int find(vector<int>& parents, int i){
        return parents[i] == i ? i : find(parents, parents[i]);
    }
    void uni(vector<int>& parents, vector<int>& rank, vector<int>& weights, int i, int j, int w){
        int parent_i = find(parents, i), parent_j = find(parents, j);
        if(rank[parent_i] < rank[parent_j]){
            parents[parent_i] = parent_j;
            weights[parent_j] &= (weights[parent_i] & w);
        }
        else if(rank[parent_j] < rank[parent_i]){
            parents[parent_j] = parent_i;
            weights[parent_i] &= (weights[parent_j] & w);
        }
        else{
            parents[parent_j] = parent_i;
            weights[parent_i] &= (weights[parent_j] & w);
            rank[parent_i]++;
        }
        return;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // using Union-Find
        // reference: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/solutions/4985451/c-java-python3-union-find/?envType=daily-question&envId=2025-03-20
        vector<int> ans;
        vector<int> parents(n), rank(n, 0), weights(n, -1);
        for(int i = 0; i < n; i++){
            parents[i] = i;
        }
        for(vector<int>& edge: edges){
            uni(parents, rank, weights, edge[0], edge[1], edge[2]);
        }
        for(vector<int>& q: query){
            int parent_i = find(parents, q[0]), parent_j = find(parents, q[1]);
            if(parent_i != parent_j)
                ans.push_back(-1);
            else
                ans.push_back(weights[parent_i]);
        }
        return ans;
    }
};