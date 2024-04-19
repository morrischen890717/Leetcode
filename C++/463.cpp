class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0, repeat = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    cnt++;
                    if(i - 1 >= 0 && grid[i - 1][j])
                        repeat++;
                    if(j - 1 >= 0 && grid[i][j - 1])
                        repeat++;
                }
            }
        }
        return 4 * cnt - 2 * repeat;
    }
};