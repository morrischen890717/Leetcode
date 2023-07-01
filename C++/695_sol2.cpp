class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;
                    while(!q.empty()){
                        int size = q.size();
                        cnt += size;
                        for(int k = 0; k < size; k++){
                            pair<int, int> p = q.front();
                            q.pop();
                            int x = p.first, y = p.second;
                            for(int t = 0; t < 4; t++){
                                int new_x = x + dirs[t], new_y = y + dirs[t + 1];
                                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 1){
                                    grid[new_x][new_y] = 0;
                                    q.push({new_x, new_y});
                                }
                            }
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};