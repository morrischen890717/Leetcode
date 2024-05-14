class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - 2, vector<int> (n - 2));
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                int max_num = INT_MIN;
                for(int k = -1; k <= 1; k++){
                    for(int t = -1; t <= 1; t++){
                        max_num = max(max_num, grid[i + k][j + t]);
                    }
                }
                ans[i - 1][j - 1] = max_num;
            }
        }
        return ans;
    }
};