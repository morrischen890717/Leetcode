class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> row(m, {INT_MAX, -1}), col(n, {INT_MIN, -1});
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] > col[j].first)
                    col[j] = {matrix[i][j], i};
                if(matrix[i][j] < row[i].first)
                    row[i] = {matrix[i][j], j};
            }
        }
        vector<int> ans;
        for(int i = 0; i < m; i++){
            if(col[row[i].second].second == i)
                ans.push_back(row[i].first);
        }
        return ans;
    }
};