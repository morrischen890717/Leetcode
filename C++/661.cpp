class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ans(m, vector<int> (n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int cnt = 0, sum = 0;
                for(int k = -1; k <= 1; k++){
                    for(int t = -1; t <= 1; t++){
                        int new_i = i + k, new_j = j + t;
                        if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n){
                            cnt++;
                            sum += img[new_i][new_j];
                        }
                    }
                }
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
};