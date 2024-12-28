class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // using bottom-up DP
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/solutions/108231/c-java-dp-with-explanation-o-n/?envType=daily-question&envId=2024-12-28
        int n = nums.size();
        vector<int> prefix(n + 1, 0), leftPos(n, -1), rightPos(n, -1), ans;
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int val = 0;
        for(int i = k; i < n; i++){
            int curVal = prefix[i] - prefix[i - k];
            if(curVal > val){
                leftPos[i] = i - k;
                val = curVal;
            }
            else
                leftPos[i] = leftPos[i - 1];
        }
        val = 0;
        for(int i = n - k; i >= 0; i--){
            int curVal = prefix[i + k] - prefix[i];
            if(curVal >= val){
                rightPos[i] = i;
                val = curVal;
            }
            else
                rightPos[i] = rightPos[i + 1];
        }
        int maxSum = 0;
        for(int i = k; i <= n - 2 * k; i++){
            int curVal = prefix[i + k] - prefix[i];
            int leftVal = prefix[leftPos[i] + k] - prefix[leftPos[i]];
            int rightVal = prefix[rightPos[i + k] + k] - prefix[rightPos[i + k]];
            int curSum = curVal + leftVal + rightVal;
            if(curSum > maxSum){
                ans = {leftPos[i], i, rightPos[i + k]};
                maxSum = curSum;
            }
        }
        return ans;
    }
};