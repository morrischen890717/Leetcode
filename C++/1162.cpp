class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // using BFS
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j])
                    q.push({i, j});
            }
        }
        if(q.size() == 0 || q.size() == m * n)
            return -1;
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> p = q.front();
                int x = p.first, y = p.second;
                q.pop();
                for(int j = 0; j < 4; j++){
                    int new_x = x + dirs[j], new_y = y + dirs[j + 1];
                    if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !grid[new_x][new_y]){
                        grid[new_x][new_y] = 1; // visited
                        q.push({new_x, new_y});
                    }
                }
            }
            dist++;
        }
        return dist - 1;
    }
};