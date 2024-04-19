class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // using BFS
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        queue<pair<int, int>> q;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    grid[i][j] = '0';
                    q.push({i, j});
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        int r = p.first, c = p.second;
                        for(int k = 0; k < 4; k++){
                            int new_r = r + dirs[k], new_c = c + dirs[k + 1];
                            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && grid[new_r][new_c] == '1'){
                                grid[new_r][new_c] = '0';
                                q.push({new_r, new_c});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};