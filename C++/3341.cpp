class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            int time = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();
            if(i == n - 1 && j == m - 1)
                return time;
            for(int k = 0; k < 4; k++){
                int new_i = i + dirs[k], new_j = j + dirs[k + 1];
                if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && moveTime[new_i][new_j] != -1){
                    pq.push({1 + max(time, moveTime[new_i][new_j]), {new_i, new_j}});
                    moveTime[new_i][new_j] = -1; // visited
                }
            }
        }
        return -1;
    }
};