class Solution {
public:
    void dfs(vector<vector<int>>& grid, int n, int i, int j, int num, vector<int>& dir, queue<pair<int, int>>& q){
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1)
            return;
        grid[i][j] = num;
        for(int k = 0; k < 4; k++){
            dfs(grid, n, i + dir[k], j + dir[k + 1], num, dir, q);
        }
        q.push({i, j});
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        /*
        using DFS to find one of the islands, ans using BFS to connect two islands
        reference: https://leetcode.com/problems/shortest-bridge/solutions/189293/c-bfs-island-expansion-uf-bonus/
        */
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<int> dir = {1, 0, -1, 0, 1};
        int num = 2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dfs(grid, n, i, j, num, dir, q);
                    break;
                }
            }
            if(!q.empty())
                break;
        }
        while(!q.empty()){ // BFS
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> p = q.front();
                q.pop();
                int r = p.first, c = p.second;
                for(int j = 0; j < 4; j++){
                    int new_r = r + dir[j], new_c = c + dir[j + 1];
                    if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < n){
                        if(grid[new_r][new_c] == 1)
                            return grid[r][c] - num;
                        else if(grid[new_r][new_c] == 0){
                            grid[new_r][new_c] = grid[r][c] + 1;
                            q.push({new_r, new_c});
                        }
                    }
                }
            }
        }
        return -1;
    }
};