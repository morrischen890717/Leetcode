class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row_cnt(m, 0), col_cnt(n, 0);
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    cnt++;
                    row_cnt[i]++;
                    col_cnt[j]++;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && row_cnt[i] == 1 && col_cnt[j] == 1)
                    cnt--;
            }
        }
        return cnt;
    }
};