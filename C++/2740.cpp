class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int val = INT_MAX;
        int prev = nums[0];
        for(int i = 1; i < n; i++){
            val = min(val, nums[i] - prev);
            prev = nums[i];
        }
        return val;
    }
};