class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char> (m, '.'));
        for(int i = 0; i < m; i++){
            int cnt = 0;
            for(int j = 0; j <= n; j++){
                if(j == n || box[i][j] == '*'){
                    if(j < n && box[i][j] == '*')
                        ans[j][m - 1 - i] = '*';
                    for(int k = 1; k <= cnt; k++){
                        ans[j - k][m - 1 - i] = '#';
                    }
                    cnt = 0;
                }
                else if(box[i][j] == '#')
                    cnt++;
            }
        }
        return ans;
    }
};