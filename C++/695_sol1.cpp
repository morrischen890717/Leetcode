class Solution {
public:
    int dfs(vector<vector<int>>& grid, int m, int n, vector<int>& dirs, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;
        int res = 1;
        grid[i][j] = 0;
        for(int k = 0; k < 4; k++){
            res += dfs(grid, m, n, dirs, i + dirs[k], j + dirs[k + 1]);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dfs(grid, m, n, dirs, i, j));
            }
        }
        return ans;
    }
};