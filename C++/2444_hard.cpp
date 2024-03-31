class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // using sliding window
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/solutions/2708099/java-c-python-sliding-window-with-explanation/?envType=daily-question&envId=2024-03-31
        long long ans = 0;
        int n = nums.size();
        int last_min = -1, last_max = -1, last_bad = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == minK)
                last_min = i;
            if(nums[i] == maxK)
                last_max = i;
            if(nums[i] < minK || nums[i] > maxK)
                last_bad = i;
            ans += max(0, min(last_min, last_max) - last_bad);
        }
        return ans;
    }
};