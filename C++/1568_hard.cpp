class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<int>& dirs, int m, int n, int i, int j){
        for(int k = 0; k < 4; k++){
            int new_i = i + dirs[k], new_j = j + dirs[k + 1];
            if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] && !visited[new_i][new_j]){
                visited[new_i][new_j] = true;
                dfs(grid, visited, dirs, m, n, new_i, new_j);
            }
        }
        return;
    }
    int countIslands(vector<vector<int>>& grid, int m, int n){
        vector<int> dirs = {-1, 0, 1, 0, -1};
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] && !visited[i][j]){
                    cnt++;
                    visited[i][j] = true;
                    dfs(grid, visited, dirs, m, n, i, j);
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        // using DFS
        // time complexity: O((M * N)^2), space complexity: O(M * N), where M == grid.size() and N == grid[0].size()
        // reference: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/solutions/819296/dfs-c-clean-code-with-explanation/?envType=daily-question&envId=2024-08-11
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        if(countIslands(grid, m, n) != 1)
            return 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    if(countIslands(grid, m, n) != 1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};