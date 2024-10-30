class Solution {
public:
    vector<int> getLen(vector<int>& nums){
        int n = nums.size();
        vector<int> v = {nums[0]}, maxLen(n, 1);
        for(int i = 1; i < n; i++){
            if(nums[i] > v.back())
                v.push_back(nums[i]);
            else{
                int pos = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[pos] = nums[i];
            }
            maxLen[i] = v.size();
        }
        return maxLen;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        // using lower_bound
        // reference: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/solutions/5984675/explained-step-by-step-beats-100-working-30-10-2024/?envType=daily-question&envId=2024-10-30
        int ans = INT_MAX;
        int n = nums.size();
        vector<int> nums_reverse(nums.rbegin(), nums.rend());
        nums = getLen(nums);
        nums_reverse = getLen(nums_reverse);
        for(int i = 0; i < n; i++){
            if(nums[i] > 1 && nums_reverse[n - 1 - i] > 1)
                ans = min(ans, n - (nums[i] + nums_reverse[n - 1 - i] - 1));
        }
        return ans;
    }
};