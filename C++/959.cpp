class Solution {
public:
    bool dfs(vector<vector<bool>>& g, vector<int>& dirs, int i, int j){
        if(i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || g[i][j])
            return false;
        g[i][j] = true;
        for(int k = 0; k < 4; k++){
            int new_i = i + dirs[k], new_j = j + dirs[k + 1];
            dfs(g, dirs, new_i, new_j);
        }
        return true;
    }
    int regionsBySlashes(vector<string>& grid) {
        // using DFS
        // time complexity: O(N^2), space complexity: O(N^2)
        // reference: https://leetcode.com/problems/regions-cut-by-slashes/solutions/205674/dfs-on-upscaled-grid/
        int n = grid.size();
        vector<int> dirs = {1, 0, -1, 0, 1};
        vector<vector<bool>> g(n * 3, vector<bool> (n * 3, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/')
                    g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = true;
                else if(grid[i][j] == '\\')
                    g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = true;
            }
        }
        int ans = 0;
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g[0].size(); j++){
                ans += dfs(g, dirs, i, j) ? 1 : 0;
            }
        }
        return ans;
    }
};