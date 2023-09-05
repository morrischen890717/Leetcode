class Solution {
public:
    void dilate(queue<pair<int, int>>& q, vector<int>& dirs, int m, int n, int x, int y){
        for(int i = 0; i < 4; i++){
            int new_x = x + dirs[i], new_y = y + dirs[i + 1];
            if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n)
                q.push({new_x, new_y});
        }
        return;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // using BFS
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {1, 0, -1, 0, 1};
        queue<pair<int, int>> q;
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    grid[i][j] = -1;
                    dilate(q, dirs, m, n, i, j);
                }
                else if(grid[i][j] == 0)
                    grid[i][j] = -1;
                else
                    cnt++;
            }
        }
        if(cnt == 0)
            return 0;
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> p = q.front();
                int x = p.first, y = p.second;
                q.pop();
                if(grid[x][y] == -1)
                    continue;
                else{
                    cnt--;
                    grid[x][y] = -1;
                    dilate(q, dirs, m, n, x, y);
                }
            }
            time++;
            if(cnt == 0)
                return time;
        }
        return -1;
    }
};