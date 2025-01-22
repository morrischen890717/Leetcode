class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // using BFS
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int> (n, -1));
        vector<int> dirs = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j]){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int h = 1;
        while(!q.empty()){
            int size = q.size();
            for(int t = 0; t < size; t++){
                int i = q.front().first, j = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int new_i = i + dirs[k], new_j = j + dirs[k + 1];
                    if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && ans[new_i][new_j] == -1){
                        ans[new_i][new_j] = h;
                        q.push({new_i, new_j});
                    }
                }
            }
            h++;
        }
        return ans;
    }
};