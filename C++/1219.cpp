class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<int>& dirs, int m, int n, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;
        int sum = 0;
        int amount = grid[i][j];
        grid[i][j] = 0; // visited
        for(int k = 0; k < 4; k++){
            int new_i = i + dirs[k], new_j = j + dirs[k + 1];
            sum = max(sum, amount + solve(grid, dirs, m, n, new_i, new_j));
        }
        grid[i][j] = amount;
        return sum;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, solve(grid, dirs, m, n, i, j));
            }
        }
        return ans;
    }
};