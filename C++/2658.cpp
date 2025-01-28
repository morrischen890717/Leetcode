class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] <= 0)
                    continue;
                int cnt = grid[i][j];
                grid[i][j] = -1;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    int size = q.size();
                    for(int k = 0; k < size; k++){
                        pair<int, int> p = q.front();
                        q.pop();
                        for(int t = 0; t < 4; t++){
                            int new_i = p.first + dirs[t], new_j = p.second + dirs[t + 1];
                            if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] > 0){
                                cnt += grid[new_i][new_j];
                                grid[new_i][new_j] = -1;
                                q.push({new_i, new_j});
                            }
                        }
                    }
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};