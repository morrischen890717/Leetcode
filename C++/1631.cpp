class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // using priority_queue and Dijkstra Algorithm
        // reference: https://leetcode.com/problems/path-with-minimum-effort/solutions/909017/java-python-dijikstra-binary-search-clean-concise/?envType=daily-question&envId=2023-09-16
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> d(m, vector<int> (n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<int> dirs = {1, 0, -1, 0, 1};
        while(!pq.empty()){
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int dist = p.first;
            int r = p.second.first, c = p.second.second;
            if(r == m - 1 && c == n - 1)
                return dist;
            for(int k = 0; k < 4; k++){
                int new_r = r + dirs[k], new_c = c + dirs[k + 1];
                if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n){
                    int new_dist = max(dist, abs(heights[new_r][new_c] - heights[r][c]));
                    if(new_dist < d[new_r][new_c]){
                        d[new_r][new_c] = new_dist;
                        pq.push({new_dist, {new_r, new_c}});
                    }
                }
            }
        }
        return -1;
    }
};