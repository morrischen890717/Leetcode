class Solution {
public:
    int find(vector<int>& parent, int i){
        return i == parent[i] ? i : find(parent, parent[i]);
    }
    bool uni(vector<int>& parent, vector<int>& rank, int i, int j){
        int root_i = find(parent, i), root_j = find(parent, j);
        if(root_i == root_j)
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        // using Union-Find(union by rank), sort()
        int ans = 0;
        int n = points.size();
        vector<int> parent(n), rank(n, 0);
        vector<pair<int, pair<int, int>>> dist;
        for(int i = 0; i < n; i++){
            parent[i] = i;
            for(int j = i + 1; j < n; j++){
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                dist.push_back({d, {i, j}});
            }
        }
        sort(dist.begin(), dist.end());
        int cnt = 0; // we need exactly n - 1 edges to connect all the points with minimum cost
        for(int k = 0; k < dist.size() && cnt < n - 1; k++){
            if(uni(parent, rank, dist[k].second.first, dist[k].second.second)){
                ans += dist[k].first;
                cnt++;
            }
        }
        return ans;
    }
};