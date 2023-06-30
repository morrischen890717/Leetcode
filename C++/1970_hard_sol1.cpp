class Solution {
public:
    bool dfs(vector<vector<int>>& grid, vector<int>& dirs, int& row, int& col, int i, int j){
        if(i < 0 || i >= row ||j < 0 || j >= col || grid[i][j] == 1 || grid[i][j] == -1)
            return false;
        if(i == row - 1)
            return true;
        grid[i][j] = -1; // visited
        for(int k = 0; k < 4; k++){
            int new_i = i + dirs[k], new_j = j + dirs[k + 1];
            if(dfs(grid, dirs, row, col, new_i, new_j)){
                return true;
            }
        }
        return false;
    }
    bool canCross(vector<vector<int>>& cells, int& row, int& col, vector<int>& dirs, int day){
        vector<vector<int>> grid(row, vector<int> (col, 0));
        for(int i = 0; i < day; i++){
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        for(int j = 0; j < col; j++){
            if(dfs(grid, dirs, row, col, 0, j))
                return true;
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        /*
        using binary search + DFS
        */
        vector<int> dirs = {-1, 0, 1, 0, -1};
        int l = 0, r = cells.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(canCross(cells, row, col, dirs, mid))
                l = mid + 1;
            else
                r = mid - 1;
        }
        return max(0, r);
    }
};