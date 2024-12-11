class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        for(int r = 0; r < n; r++){
            while(nums[r] - nums[l] > 2 * k){
                ans = max(ans, r - l);
                l++;
            }
        }
        ans = max(ans, n - l);
        return ans;
    }
};