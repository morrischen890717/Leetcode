class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // using BFS
        // reference: https://leetcode.com/problems/trapping-rain-water-ii/solutions/1138028/python3-visualization-bfs-solution-with-explanation/?envType=daily-question&envId=2025-01-19
        int ans = 0;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    pq.push({heightMap[i][j], {i, j}});
                    heightMap[i][j] = -1; // visited
                }
            }
        }
        while(!pq.empty()){
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int h = p.first, i = p.second.first, j = p.second.second;
            for(int k = 0; k < 4; k++){
                int new_i = i + dirs[k], new_j = j + dirs[k + 1];
                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && heightMap[new_i][new_j] != -1){
                    if(heightMap[new_i][new_j] < h){
                        ans += h - heightMap[new_i][new_j];
                        pq.push({h, {new_i, new_j}});
                    }
                    else
                        pq.push({heightMap[new_i][new_j], {new_i, new_j}});
                    heightMap[new_i][new_j] = -1;
                }
            }
        }
        return ans;
    }
};