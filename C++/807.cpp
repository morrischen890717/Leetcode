class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans += min(row[i], col[j]) - grid[i][j];
            }
        }
        return ans;
    }
};