class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        // using sort and priority_queue
        vector<int> ans(queries.size());
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<pair<int, int>> q;
        for(int i = 0; i < queries.size(); i++){
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        pq.push({grid[0][0], {0, 0}});
        grid[0][0] = -1; // visited
        int res = 0;
        for(pair<int, int> p: q){
            while(!pq.empty() && pq.top().first < p.first){
                pair<int, int> pp = pq.top().second;
                pq.pop();
                res++;
                for(int k = 0; k < 4; k++){
                    int new_r = pp.first + dirs[k], new_c = pp.second + dirs[k + 1];
                    if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && grid[new_r][new_c] != -1){
                        pq.push({grid[new_r][new_c], {new_r, new_c}});
                        grid[new_r][new_c] = -1; // visited
                    }
                }
            }
            ans[p.second] = res;
        }
        return ans;
    }
};