class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row_cnt(m, 0), col_cnt(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    row_cnt[i]++;
                    col_cnt[j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] && row_cnt[i] == 1 && col_cnt[j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};