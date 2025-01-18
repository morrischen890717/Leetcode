class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, vector<vector<int>>& dirs, queue<pair<int, int>>& q, int i, int j, int cost){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || dp[i][j] != INT_MAX)
            return;
        dp[i][j] = cost;
        q.push({i, j});
        int new_i = i + dirs[grid[i][j] - 1][0], new_j = j + dirs[grid[i][j] - 1][1];
        dfs(grid, dp, dirs, q, new_i, new_j, cost);
        return;
    }
    int minCost(vector<vector<int>>& grid) {
        // using BFS and DFS
        // time complexity: O(M * N), space complexity: O(M * N), where M == grid.size() and N == grid[0].size()
        // reference: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/solutions/524886/java-c-python-bfs-and-dfs/?envType=daily-question&envId=2025-01-18
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, INT_MAX));
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        int cost = 0;
        dfs(grid, dp, dirs, q, 0, 0, cost);
        while(!q.empty()){
            cost++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> p = q.front();
                q.pop();
                for(vector<int>& dir: dirs){
                    dfs(grid, dp, dirs, q, p.first + dir[0], p.second + dir[1], cost);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};