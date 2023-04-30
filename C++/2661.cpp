class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m * n + 1), col(m * n + 1);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                row[mat[i][j]] = i;
                col[mat[i][j]] = j;
            }
        }
        vector<int> cnt_row(m, 0);
        vector<int> cnt_col(n, 0);
        for(int i = 0; i < m * n; i++){
            cnt_row[row[arr[i]]]++;
            cnt_col[col[arr[i]]]++;
            if(cnt_row[row[arr[i]]] == n || cnt_col[col[arr[i]]] == m)
                return i;
        }
        return -1;
    }
};