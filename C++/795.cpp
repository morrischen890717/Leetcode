class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        // using two-pointers
        // time complexity: O(N), space complexity: O(1)
        int ans = 0;
        int l = 0, last = -1; // last stands for the last position which val is between left and right
        int n = nums.size();
        for(int r = 0; r < n; r++){
            if(nums[r] > right){
                l = r + 1;
                last = -1;
            }
            else if(left <= nums[r] && nums[r] <= right)
                last = r;
            if(last != -1) // means that at least one element which val is between left and right
                ans += (last - l + 1);
        }
        return ans;
    }
};