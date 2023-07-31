class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        // using Greedy
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            bool toggle = grid[i][0] == 0;
            int num = 0;
            for(int j = 0; j < n; j++){
                num <<= 1;
                if(toggle)
                    grid[i][j] = !grid[i][j];
                num |= (grid[i][j]);
            }
            ans += num;
        }
        for(int j = 0; j < n; j++){
            int cnt1 = 0;
            for(int i = 0; i < m; i++){
                if(grid[i][j])
                    cnt1++;
            }
            if(m - cnt1 > cnt1){ // # of 0 > # of 1
                ans += pow(2, n - 1 - j) * (m - 2 * cnt1);
            }
        }
        return ans;
    }
};