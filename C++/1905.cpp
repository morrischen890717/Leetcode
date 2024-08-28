class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // using BFS
        int ans = 0;
        int m = grid2.size(), n = grid2[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j]){
                    bool valid = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid2[i][j] = 0;
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        if(!grid1[p.first][p.second])
                            valid = false;
                        for(int k = 0; k < 4; k++){
                            int new_i = p.first + dirs[k], new_j = p.second + dirs[k + 1];
                            if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid2[new_i][new_j]){
                                q.push({new_i, new_j});
                                grid2[new_i][new_j] = 0;
                            }
                        }
                    }
                    if(valid)
                        ans++;
                }
            }
        }
        return ans;
    }
};