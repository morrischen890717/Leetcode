class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<int>& dirs, int i, int j){
        int max_val = grid[i][j];
        int tmp = grid[i][j];
        for(int k = 0; k < 4; k++){
            int new_i = i + dirs[k], new_j = j + dirs[k + 1];
            if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && grid[new_i][new_j] != 0){
                grid[i][j] = 0; // visited
                max_val = max(max_val, tmp + dfs(grid, dirs, new_i, new_j));
                grid[i][j] = tmp; // have not visited yet
            }
        }
        return max_val;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0)
                   ans = max(ans, dfs(grid, dirs, i, j));
            }
        }
        return ans;
    }
};