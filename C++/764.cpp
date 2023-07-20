class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        /*
        time complexity: O(N^2), space complexity: O(N^2)
        reference: https://leetcode.com/problems/largest-plus-sign/solutions/113314/java-c-python-o-n-2-solution-using-only-one-grid-matrix/
        */
        int ans = 0;
        vector<vector<int>> grid(n, vector<int> (n, n));
        for(vector<int>& mine: mines){
            grid[mine[0]][mine[1]] = 0;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0, l = 0; j < n; j++){
                // j is a column index, iterate from left to right
                // every time check how far left it can reach.
                // if grid[i][j] is 0, l needs to start over from 0 again, otherwise 
                grid[i][j] = min(grid[i][j], l = (grid[i][j] == 0 ? 0 : l + 1));
            }
            for(int j = n - 1, r = 0; j >= 0; j--){
                // k is a column index, iterate from right to left
                // every time check how far right it can reach.
                // if grid[i][k] is 0, r needs to start over from 0 again, otherwise 
                grid[i][j] = min(grid[i][j], r = (grid[i][j] == 0 ? 0 : r + 1));
            }
            for(int j = 0, u = 0; j < n; j++){
                // j is a row index, iterate from top to bottom
                // every time check how far up it can reach.
                // if grid[j][i] is 0, u needs to start over from 0 again, otherwise 
                grid[j][i] = min(grid[j][i], u = (grid[j][i] == 0 ? 0 : u + 1));
            }
            for(int j = n - 1, d = 0; j >= 0; j--){
                // k is a row index, iterate from bottom to top
                // every time check how far down it can reach.
                // if grid[k][i] is 0, d needs to start over from 0 again, otherwise 
                grid[j][i] = min(grid[j][i], d = (grid[j][i] == 0 ? 0 : d + 1));
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, grid[i][j]);
            }
        }
        return ans;
    }
};