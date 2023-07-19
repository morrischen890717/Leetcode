class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<int>& dirs, int m, int n, int i, int j){
        if(dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = 1; // matrix[i][j] itself
        for(int k = 0; k < 4; k++){
            int new_i = i + dirs[k], new_j = j + dirs[k + 1];
            if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || matrix[new_i][new_j] <= matrix[i][j])
                continue;
            dp[i][j] = max(dp[i][j], 1 + dfs(matrix, dp, dirs, m, n, new_i, new_j));
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        vector<int> dirs = {-1, 0, 1, 0, -1};
        int max_len = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;j++){
                max_len = max(max_len, dfs(matrix, dp, dirs, m, n, i, j));
            }
        }
        return max_len;
    }
};