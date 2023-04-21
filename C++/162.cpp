class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        int l = 0, r = n - 1;
        while(l <= r){  // binary search
            int i = (l + r) / 2;
            if((i == 0 && nums[i + 1] < nums[i]) || (i == n - 1 && nums[i - 1] < nums[i]) || (i != 0 && i != n - 1 && nums[i - 1] < nums[i] && nums[i + 1] < nums[i]))
                return i;
            if(i == 0){
                l = i + 1;
                continue;
            }
            else if(i == n - 1){
                r = i - 1;
                continue;
            }
            int slope = nums[i + 1] - nums[i];
            if(slope <= 0)  // because the slope of nums[-1] will be negative and the slope of nums[n - 1] will be positive
                r = i - 1;
            else
                l = i + 1;
        }
        return -1;
    }
};