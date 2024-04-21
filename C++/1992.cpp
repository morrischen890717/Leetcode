class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        // using BFS
        vector<vector<int>> ans;
        int m = land.size(), n = land[0].size();
        vector<vector<int>> dirs = {{1, 0}, {0, 1}};
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(land[i][j]){
                    vector<int> group = {i, j}, last = {i, j};
                    q.push({i, j});
                    land[i][j] = 0;
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        for(vector<int>& dir: dirs){
                            int new_i = p.first + dir[0], new_j = p.second + dir[1];
                            if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && land[new_i][new_j]){
                                land[new_i][new_j] = 0;
                                q.push({new_i, new_j});
                                last = {new_i, new_j};
                            }
                        }
                    }
                    group.push_back(last[0]);
                    group.push_back(last[1]);
                    ans.push_back(group);
                }
            }
        }
        return ans;
    }
};