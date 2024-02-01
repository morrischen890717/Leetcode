class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // using prefix sum
        // time complexity: O(M^2 * N^2), space complexity: O(M * N), where M == matrix.size() and N == matrix[0].size()
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefix(m + 1, vector<int> (n + 1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                prefix[i + 1][j + 1] = matrix[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
            }
        }
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                for(int k = 0; k < i; k++){
                    for(int t = 0; t < j; t++){
                        if(prefix[i][j] - prefix[i][t] - prefix[k][j] + prefix[k][t] == target)
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};