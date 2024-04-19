class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<int>& dirs, int i, int j){
        for(int k = 0; k < 4; k++){
            int new_i = i + dirs[k], new_j = j + dirs[k + 1];
            if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && grid[new_i][new_j] == '1'){
                grid[new_i][new_j] = '0';
                dfs(grid, dirs, new_i, new_j);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        // using DFS
        int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(grid, dirs, i, j);
                }
            }
        }
        return cnt;
    }
};