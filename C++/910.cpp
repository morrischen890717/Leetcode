class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        // using math and Greedy
        // reference: https://leetcode.com/problems/smallest-range-ii/solutions/173389/simple-c-solution-with-explanation/
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[n - 1] - nums[0], left = nums[0] + k, right = nums[n - 1] - k;
        for(int i = 0 ; i < n - 1; i++){
            int maxNum = max(nums[i] + k, right);
            int minNum = min(nums[i + 1] - k, left);
            ans = min(ans, maxNum - minNum);
        }
        return ans;
    }
};