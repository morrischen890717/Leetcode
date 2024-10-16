class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // using priority_queue
        vector<int> ans = {-1000000, 1000000};
        int n = nums.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int cur_max = -1000000;
        for(int i = 0; i < n; i++){
            pq.push({nums[i][0], {i, 0}});
            cur_max = max(cur_max, nums[i][0]);
        }
        while(true){
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            if(cur_max - p.first < ans[1] - ans[0])
                ans = {p.first, cur_max};
            if(p.second.second == nums[p.second.first].size() - 1)
                return ans;
            pq.push({nums[p.second.first][p.second.second + 1], {p.second.first, p.second.second + 1}});
            cur_max = max(cur_max, nums[p.second.first][p.second.second + 1]);
        }
        return {-1, -1};
    }
};