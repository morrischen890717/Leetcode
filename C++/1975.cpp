class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        long long sum = 0, cnt = 0, remain = LLONG_MAX;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0)
                    cnt++;
                if(abs(matrix[i][j]) < remain)
                    remain = abs(matrix[i][j]);
            }
        }
        return cnt % 2 ? sum - 2 * remain : sum;
    }
};