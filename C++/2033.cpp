class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> nums;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        int mid = nums[m * n / 2];
        int ans = 0;
        for(int num: nums){
            int diff = abs(mid - num);
            if(diff % x)
                return -1;
            ans += diff / x;
        }
        return ans;
    }
};