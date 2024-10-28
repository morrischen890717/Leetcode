class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // using bottom-up DP
        // time complexity: O(M * N), where M == matrix.size() and N == matrix[0].size()
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i > 0 && j > 0 && matrix[i][j])
                    matrix[i][j] += min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]});
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};