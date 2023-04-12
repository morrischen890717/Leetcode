class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_reach = nums[0];
        for(int i = 0; i < n && i <= max_reach; i++){
            max_reach = max(max_reach, i + nums[i]);
        }
        return max_reach >= n - 1;
    }
};