class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        // using BFS
        vector<vector<int>> ans(grid.begin(), grid.end());
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {1, 0, -1, 0, 1};
        queue<pair<int, int>> q;
        q.push({row, col});
        int c = grid[row][col];
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            if(grid[p.first][p.second] != c)
                continue;
            grid[p.first][p.second] = -1; // visited
            for(int i = 0; i < 4; i++){
                int new_row = p.first + dirs[i], new_col = p.second + dirs[i + 1];
                if(new_row < 0 || new_row >= m || new_col < 0 || new_col >= n || (grid[new_row][new_col] != c && grid[new_row][new_col] != -1))
                    ans[p.first][p.second] = color;
                if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && grid[new_row][new_col] == c)
                    q.push({new_row, new_col});
            }
        }
        return ans;
    }
};