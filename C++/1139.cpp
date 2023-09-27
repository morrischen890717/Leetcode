class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        // using bottom-up DP
        // time complexity: O(N^3), space complexity: O(N^2)
        int max_len = 0;
        int m = grid.size(), n = grid[0].size();
        /*
        row[i][j] stands for the biggest consecutive 1 from grid[i][j] in row direction(left <-> right)
        col[i][j] stands for the biggest consecutive 1 from grid[i][j] in col direction(up <-> down)
        */
        vector<vector<int>> row(m, vector<int> (n, 0));
        vector<vector<int>> col(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    row[i][j] = (j == 0 ? 0 : row[i][j - 1]) + 1;
                    col[i][j] = (i == 0 ? 0 : col[i - 1][j]) + 1;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int len = min(row[i][j], col[i][j]);
                for(int l = len; l > 0; l--){
                    if(row[i - l + 1][j] >= l && col[i][j - l + 1] >= l){
                        max_len = max(max_len, l);
                        break;
                    }
                }
            }
        }
        return max_len * max_len;
    }
};