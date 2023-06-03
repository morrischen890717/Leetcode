class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if((mid == 0 && nums[mid] != nums[mid + 1]) || (mid == n - 1 && nums[mid] != nums[mid - 1]) || (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]))
                return nums[mid];
            else if(mid == 0)
                l = mid + 1;
            else if(mid == n - 1)
                r = mid - 1;
            else if(nums[mid] == nums[mid + 1]){
                if(mid % 2)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else{
                if(mid % 2)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};