class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        // using prefix sum
        // time complexity: O(M * N), space complexity: O(M * N)
        // reference: https://leetcode.com/problems/matrix-block-sum/solutions/500833/c-prefix-sum-with-explanation/
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int> (n + 1, 0)); // prefix[i][j] stands the sum of the rectangle constructed by two points (0, 0), (i - 1, j - 1)
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans(m, vector<int> (n, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int max_i = min(m, i + k), max_j = min(n, j + k);
                int min_i = max(1, i - k), min_j = max(1, j - k);
                ans[i - 1][j - 1] = prefix[max_i][max_j] - prefix[min_i - 1][max_j] - prefix[max_i][min_j - 1] + prefix[min_i - 1][min_j - 1];
            }
        }
        return ans;
    }
};