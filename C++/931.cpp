class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // using bottom-up DP
        // time complexity: O(M * N), space complexity: O(1) (for extra space)
        int m = matrix.size(), n = matrix[0].size();
        for(int i = m - 1; i >= 1; i--){
            for(int j = 0; j < n; j++){
                int left = j == 0 ? INT_MAX : matrix[i][j - 1], mid = matrix[i][j], right = j == n - 1 ? INT_MAX : matrix[i][j + 1];
                matrix[i - 1][j] += min({left, mid, right});
            }
        }
        int minSum = INT_MAX;
        for(int j = 0; j < n; j++){
            minSum = min(minSum, matrix[0][j]);
        }
        return minSum;
    }
};