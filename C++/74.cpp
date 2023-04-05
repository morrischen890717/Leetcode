class Solution {
public:
    bool binary_search(vector<int> row, int target){
        int n = row.size();
        int l = 0, r = n - 1;
        int curr;
        while(l <= r){
            curr = (l + r) / 2;
            if(row[curr] == target)
                return true;
            else if(row[curr] < target)
                l = curr + 1;
            else
                r = curr - 1;
        }
        return false;
    }
    int find_row(vector<vector<int>>& matrix, int target){
        int n = matrix.size();
        int l = 0, r = n - 1;
        int curr;
        while(l <= r){
            curr = (l + r) / 2;
            if(curr == n - 1 && matrix[curr][0] <= target)
                return curr;
            else if(matrix[curr][0] <= target && matrix[curr + 1][0] > target)
                return curr;
            else if(matrix[curr][0] > target)
                r = curr - 1;
            else
                l = curr + 1;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int target_row = find_row(matrix, target);
        if(target_row == -1)
            return false;
        return binary_search(matrix[target_row], target);
    }
};