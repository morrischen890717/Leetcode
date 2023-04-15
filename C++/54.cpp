class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total = n * m;
        vector<int> result;
        int cnt = 0;
        int up = 0, down = n - 1, left = 0, right = m - 1;
        while(true){
            for(int i = left; i <= right; i++){
                result.push_back(matrix[up][i]);
                cnt++;
            }
            up++;
            if(cnt == total)
                break;
            for(int i = up; i <= down; i++){
                result.push_back(matrix[i][right]);
                cnt++;
            }
            right--;
            if(cnt == total)
                break;
            for(int i = right; i >= left; i--){
                result.push_back(matrix[down][i]);
                cnt++;
            }
            down--;
            if(cnt == total)
                break;
            for(int i = down; i >= up; i--){
                result.push_back(matrix[i][left]);
                cnt++;
            }
            left++;
            if(cnt == total)
                break;
        }
        return result;
    }
};