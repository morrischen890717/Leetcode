class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> cnt;
        for(int i = 0; i < n; i++){
            cnt[grid[i]]++;
        }
        int ans = 0;
        for(int j = 0; j < n; j++){
            vector<int> v(n);
            for(int i = 0; i < n; i++){
                v[i] = grid[i][j];
            }
            if(cnt.count(v) > 0)
                ans += cnt[v];
        }
        return ans;
    }
};