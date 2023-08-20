class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // using Greedy
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/178422/one-pass/
        int total = 0;
        int curMax = 0, sumMax = nums[0];
        int curMin = 0, sumMin = nums[0];
        for(int num: nums){
            curMax = max(curMax + num, num);
            sumMax = max(sumMax, curMax);
            curMin = min(curMin + num, num);
            sumMin = min(sumMin, curMin);
            total += num;
        }
        return sumMax > 0 ? max(sumMax, total - sumMin) : sumMax;
    }
};