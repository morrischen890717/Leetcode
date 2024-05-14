class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        // using Greedy
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        // make the most significant bit of all row become 1
        for(int i = 0; i < m; i++){
            bool flip = !grid[i][0];
            for(int j = 0; j < n; j++){
                if(flip)
                    grid[i][j] = !grid[i][j];
            }
        }
        for(int j = 0; j < n; j++){
            int cnt = 0;
            for(int i = 0; i < m; i++){
                cnt += grid[i][j];
            }
            ans += max(cnt, m - cnt) * (1 << (n - 1 - j));
        }
        return ans;
    }
};