class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int l = 0, r = n - 1;
        int leftmost = nums[l], rightmost = nums[r];
        while(l <= r){  // binary search
            int mid = (l + r) / 2;
            if(nums[mid] > nums[(mid + 1) % n]){
                return nums[(mid + 1) % n];
            }
            else if(nums[mid] >= leftmost){
                l = mid + 1;
            }
            else if(nums[mid] <= rightmost){
                r = mid - 1;
            }
        }
        return -1;
    }
};