class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0, 2});
        moveTime[0][0] = -1;
        while(!pq.empty()){
            int time = pq.top()[0], i = pq.top()[1], j = pq.top()[2], step = pq.top()[3];
            pq.pop();
            if(i == n - 1 && j == m - 1)
                return time;
            for(int k = 0; k < 4; k++){
                int new_i = i + dirs[k], new_j = j + dirs[k + 1], new_step = step == 1 ? 2 : 1;
                if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && moveTime[new_i][new_j] != -1){
                    pq.push({max(moveTime[new_i][new_j], time) + new_step, new_i, new_j, new_step});
                    moveTime[new_i][new_j] = -1;
                }
            }
        }
        return -1;
    }
};