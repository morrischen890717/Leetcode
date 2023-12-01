class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // reference: https://leetcode.com/problems/rotate-image/solutions/18872/a-common-method-to-rotate-the-image/
        int n = matrix.size();
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return;
    }
};