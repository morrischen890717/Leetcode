class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int left_slope = nums[mid] > (mid - 1 >= 0 ? nums[mid - 1] : LLONG_MIN) ? 1 : -1;
            int right_slope = (mid + 1 < n ? nums[mid + 1] : LLONG_MIN) > nums[mid] ? 1 : -1;
            if(left_slope == 1 && right_slope == -1)
                return mid;
            else if(left_slope == 1 && right_slope == 1)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};