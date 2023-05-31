class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        /*
        using bottom-up DP
        reference: https://leetcode.com/problems/01-matrix/solutions/1369741/c-java-python-bfs-dp-solutions-with-picture-clean-concise-o-1-space/
        */
        int m = mat.size(), n = mat[0].size(), INF = m + n;
        int top, left, down, right;
        for(int i = 0; i < m; i++){   // from upper left corner to lower right corner
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0)
                    continue;
                top = (i == 0 ? INF : mat[i - 1][j] + 1);
                left = (j == 0 ? INF : mat[i][j - 1] + 1);
                mat[i][j] = min(top, left);
            }
        }
        for(int i = m - 1; i >= 0; i--){   // from lower right corner to upper left corner
            for(int j = n - 1; j >= 0; j--){
                if(mat[i][j] == 0)
                    continue;
                down = (i == m - 1 ? INF : mat[i + 1][j] + 1);
                right = (j == n - 1 ? INF : mat[i][j + 1] + 1);
                mat[i][j] = min({mat[i][j], down, right});
            }
        }
        return mat;
    }
};