class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // using BFS
        int m = nums.size(), n = nums[0].size();
        vector<int> ans;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()){
            int i = q.front().first, j = q.front().second;
            q.pop();
            if(nums[i][j] == -1)
                continue;
            ans.push_back(nums[i][j]);
            nums[i][j] = -1; // visited
            if(i + 1 < m && j < nums[i + 1].size())
                q.push({i + 1, j});
            if(j + 1 < nums[i].size())
                q.push({i, j + 1});
        }
        return ans;
    }
};