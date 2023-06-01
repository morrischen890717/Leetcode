class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<int> dir = {-1, 0, 1, 0, -1, 1, 1, -1, -1};
        if(grid[0][0] == 1)
            return -1;
        q.push({0, 0});
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] = -grid[i][j];
            }
        }
        int len = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> p = q.front();
                q.pop();
                int r = p.first, c = p.second;
                if(grid[r][c] == 0){
                    grid[r][c] = len;
                    for(int j = 0; j < 8; j++){
                        int new_r = r + dir[j], new_c = c + dir[j + 1];
                        if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && grid[new_r][new_c] == 0)
                            q.push({new_r, new_c});
                    }
                }
            }
            len++;
        }
        return (grid[m - 1][n - 1] == 0 ? -1 : grid[m - 1][n - 1]);
    }
};