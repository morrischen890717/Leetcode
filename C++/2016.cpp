class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        int min_num = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] > min_num)
                ans = max(ans, nums[i] - min_num);
            else
                min_num = min(min_num, nums[i]);
        }
        return ans;
    }
};