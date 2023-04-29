class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2]; 
    }

    int find(vector<int>& parent, vector<int>& weight, int i, int limit){
        while(parent[i] != i){
            if(weight[i] >= limit)  // this is the top node which node i can reach with limit
                break;
            i = parent[i];
        }
        return i;
    }

    void union_by_size(vector<int>& parent, vector<int>& size, vector<int>& weight, int i, int j, int w){
        int root1 = find(parent, weight, i, INT_MAX);
        int root2 = find(parent, weight, j, INT_MAX);
        if(root1 != root2){
            // if the size of the root of i is less than the size of the root of j, make j the parent of i
            if(size[root1] < size[root2]){
                parent[root1] = root2;
                weight[root1] = w;
                size[root2] += size[root1];
            }
            else{
                // otherwise, make i the parent of j
                parent[root2] = root1;
                weight[root2] = w;
                size[root1] += size[root2];
            }
        }
        return;
    }

    bool check_path(vector<int>& parent, vector<int>& weight, vector<int>& query){
        return find(parent, weight, query[0], query[2]) == find(parent, weight, query[1], query[2]);    // if they can meet each other at same node with the constraint of limit(query[2]), then return true
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) { // using Union-Find Alogrithm (union by size)
        vector<int> parent(n);
        vector<int> size(n, 1);
        vector<int> weight(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        sort(edgeList.begin(), edgeList.end(), cmp);  // sort edgeList with ascending order based on the weight of the edge
        for(vector<int>& edge: edgeList){
            // because we sort edgeList first, we will union the nodes which have lower weight
            union_by_size(parent, size, weight, edge[0], edge[1], edge[2]);
        }
        vector<bool> ans(queries.size());
        for(int i = 0; i < queries.size(); i++){
            ans[i] = check_path(parent, weight, queries[i]);
        }
        return ans;
    }
};