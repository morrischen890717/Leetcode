class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int> (n, -1));
        for(int i = 0; i < m; i++){
            int r = i, c = 0;
            unordered_map<int, int> t, b;
            int num_t = 0, num_b = 0;
            while(r < m && c < n){
                b[grid[r][c]]++;
                if(b[grid[r][c]] == 1)
                    num_b++;
                r++;
                c++;
            }
            r = i, c = 0;
            while(r < m && c < n){
                b[grid[r][c]]--;
                if(b[grid[r][c]] == 0)
                    num_b--;
                ans[r][c] = abs(num_t - num_b);
                t[grid[r][c]]++;
                if(t[grid[r][c]] == 1)
                    num_t++;
                r++;
                c++;
            }
        }
        for(int i = 1; i < n; i++){
            int r = 0, c = i;
            unordered_map<int, int> t, b;
            int num_t = 0, num_b = 0;
            while(r < m && c < n){
                b[grid[r][c]]++;
                if(b[grid[r][c]] == 1)
                    num_b++;
                r++;
                c++;
            }
            r = 0, c = i;
            while(r < m && c < n){
                b[grid[r][c]]--;
                if(b[grid[r][c]] == 0)
                    num_b--;
                ans[r][c] = abs(num_t - num_b);
                t[grid[r][c]]++;
                if(t[grid[r][c]] == 1)
                    num_t++;
                r++;
                c++;
            }
        }
        return ans;
    }
};