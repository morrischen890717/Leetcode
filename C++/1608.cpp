class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= n; i++){
            int left = i < n ? nums[n - i - 1] : INT_MIN, right = i > 0 ? nums[n - i] : INT_MIN;
            if(right >= i && left < i)
                return i;
        }
        return -1;
    }
};