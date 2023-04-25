class Solution {
public:
    int binary_search(vector<int>& nums, int l, int r, int ans){
        if(r < l)
            return 10000;
        int mid = (l + r) / 2;
        int n = nums.size();
        if(nums[mid] > nums[(mid + 1) % n]) // the min val is found
            ans = nums[(mid + 1) % n];
        else if(nums[0] == nums[n - 1] && nums[0] == nums[mid]) // the min val may be in left side or right side
            ans = min({ans, binary_search(nums, l, mid - 1, ans), binary_search(nums, mid + 1, r, ans)});
        else if(nums[mid] >= nums[0]) // the min val must be in right side
            ans = binary_search(nums, mid + 1, r, ans);
        else if(nums[mid] <= nums[nums.size() - 1]) // the min val must be in left side
            ans = binary_search(nums, l, mid - 1, ans);
        return ans;        
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        return binary_search(nums, 0, n - 1, nums[0]);
    }
};