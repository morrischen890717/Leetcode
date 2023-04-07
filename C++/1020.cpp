class Solution {
public:
    void recursion(vector<vector<int>>& grid, int m, int n, int r, int c){
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 || grid[r][c] == -1)
            return;
        else{
            grid[r][c] = -1;
            recursion(grid, m, n, r - 1, c);
            recursion(grid, m, n, r + 1, c);
            recursion(grid, m, n, r, c - 1);
            recursion(grid, m, n, r, c + 1);
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            recursion(grid, m, n, i, 0);
            recursion(grid, m, n, i, n - 1);
        }
        for(int i = 0; i < n; i++){
            recursion(grid, m, n, 0, i);
            recursion(grid, m, n, m - 1, i);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};