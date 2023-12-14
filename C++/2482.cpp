class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                row[i] += grid[i][j] ? 1 : -1;
                col[j] += grid[i][j] ? 1 : -1;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] = row[i] + col[j];
            }
        }
        return grid;
    }
};