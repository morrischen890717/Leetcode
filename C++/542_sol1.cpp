class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        /*
        using BFS
        reference: https://leetcode.com/problems/01-matrix/solutions/1369741/c-java-python-bfs-dp-solutions-with-picture-clean-concise-o-1-space/
        */
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        vector<int> dir = {1, 0, -1, 0, 1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j])
                    mat[i][j] = -1;
                else
                    q.push({i, j});
            }
        }
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first, c = p.second;
            for(int i = 0; i < 4; i++){
                int new_r = r + dir[i], new_c = c + dir[i + 1];
                if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && mat[new_r][new_c] == -1){
                    mat[new_r][new_c] = mat[r][c] + 1;
                    q.push({new_r, new_c});
                }
            }
        }
        return mat;
    }
};