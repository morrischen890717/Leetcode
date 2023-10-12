class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        // using BFS
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    bool isIsland = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 2;
                    while(!q.empty()){
                        int size = q.size();
                        for(int t = 0; t < size; t++){
                            pair<int, int> p = q.front();
                            q.pop();
                            for(int k = 0; k < 4; k++){
                                int new_i = p.first + dirs[k], new_j = p.second + dirs[k + 1];
                                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == 1)
                                    continue;
                                else if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
                                    isIsland = false;
                                else if(grid[new_i][new_j] == 0){
                                    grid[new_i][new_j] = 2;
                                    q.push({new_i, new_j});
                                }
                            }
                        }
                    }
                    if(isIsland)
                        ans++;
                }
            }
        }
        return ans;
    }
};