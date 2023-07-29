class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        // using two-pointers
        // time complexity: O(N), space complexity: O(1)
        int n = nums.size();
        int ans = 0;
        int l = 0;
        int pos = -1; // the position of the last element which value is in the valid range
        int validCnt = 0; // # of elements which value is in the valid range
        for(int r = 0; r < n; r++){
            if(nums[r] > right){
                l = r + 1;
                validCnt = 0;
            }
            else if(nums[r] >= left && nums[r] <= right){
                validCnt++;
                pos = r;
            }
            if(validCnt)
                ans += (pos - l + 1);
        }
        return ans;
    }
};