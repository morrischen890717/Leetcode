class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // time complexity: O(m + n)
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        int i = 0, j = n - 1;
        while(i < m && j >= 0){
            if(grid[i][j] >= 0){
                cnt += n - j - 1;
                i++;
            }
            else
                j--;
        }
        if(i < m){
            cnt += n * (m - i);
        }
        return cnt;
    }
};