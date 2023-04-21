class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();  // time complexity: O(m + n)
        int row = 0, col = n - 1;
        while(row < m && col >= 0){    // start from top right corner
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                row++;
            else
                col--;
        }
        return false;
    }
};