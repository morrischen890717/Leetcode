class Solution {
public:
    int search(vector<int>& nums, int target) {
        // using binary search
        // time complexity: O(logN), space complexity: O(1)
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > nums.back()){
                if(target > nums[mid] || target <= nums.back())
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else if(nums[mid] < target && target <= nums.back())
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};