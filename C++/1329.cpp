class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // using unordered_map and priority_queue
        // time complexity: O(M * N * logD), where D == the length of diagonal with D = min(M,N), space complexity: O(M * N)
        // reference: https://leetcode.com/problems/sort-the-matrix-diagonally/solutions/489749/java-python-straight-forward/
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mm;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mm[i - j].push(mat[i][j]);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mat[i][j] = mm[i - j].top();
                mm[i - j].pop();
            }
        }
        return mat;
    }
};