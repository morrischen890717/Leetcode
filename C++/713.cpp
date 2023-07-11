class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int product = 1;
        int l = 0;
        int ans = 0;
        for(int r = 0; r < n; r++){
            product *= nums[r];
            while(product >= k && l <= r){
                product /= nums[l];
                l++;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};