class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        // using BFS
        vector<vector<vector<int>>> dirs = {{{0, 1}, {0, -1}}, {{1, 0}, {-1, 0}}, {{1, 0}, {0, -1}}, {{1, 0}, {0, 1}}, {{0, -1}, {-1, 0}}, {{-1, 0}, {0, 1}}};
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            if(i == m - 1 && j == n - 1)
                return true;
            if(grid[i][j] == -1)
                continue;
            int type = grid[i][j] - 1;
            grid[i][j] = -1; // visited
            for(vector<int>& dir: dirs[type]){
                int new_i = i + dir[0], new_j = j + dir[1];
                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] != -1){
                    int new_type = grid[new_i][new_j] - 1;
                    for(vector<int>& d: dirs[new_type]){
                        if(new_i + d[0] == i && new_j + d[1] == j){
                            q.push({new_i, new_j});
                            break;
                        }
                    }
                }
            }
        }
        return false;
    }
};