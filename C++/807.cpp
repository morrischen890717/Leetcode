class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<int> maxHeight(2 * n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                maxHeight[i] = max(maxHeight[i], grid[i][j]);
                maxHeight[j + n] = max(maxHeight[j + n], grid[i][j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans += (min(maxHeight[i], maxHeight[j + n]) - grid[i][j]);
            }
        }
        return ans;
    }
};