class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int ans = 0;
        vector<vector<int>> cells(m, vector<int> (n, 0));
        for(vector<int>& guard: guards){
            cells[guard[0]][guard[1]] = 1;
        }
        for(vector<int>& wall: walls){
            cells[wall[0]][wall[1]] = 2;
        }
        vector<bool> guarded_col(n, false);
        for(int i = 0; i < m; i++){
            bool guarded_row = false;
            for(int j = 0; j < n; j++){
                if(cells[i][j] == 1)
                    guarded_row = guarded_col[j] = true;
                else if(cells[i][j] == 2)
                    guarded_row = guarded_col[j] = false;
                else if(guarded_row || guarded_col[j])
                    cells[i][j] = 3;
            }
        }
        guarded_col = vector<bool> (n, false);
        for(int i = m - 1; i >= 0; i--){
            bool guarded_row = false;
            for(int j = n - 1; j >= 0; j--){
                if(cells[i][j] == 3)
                    continue;
                else if(cells[i][j] == 1)
                    guarded_row = guarded_col[j] = true;
                else if(cells[i][j] == 2)
                    guarded_row = guarded_col[j] = false;
                else if(guarded_row || guarded_col[j])
                    cells[i][j] = 3;
                else
                    ans++;
            }
        }
        return ans;
    }
};