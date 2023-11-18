class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // using sort, prefix sum, and sliding window
        // time complexity: O(NlogN), space complexity: O(1)
        // reference: https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1175088/c-maximum-sliding-window-cheatsheet-template/?envType=daily-question&envId=2023-11-18
        int n = nums.size(), ans = 1;
        sort(nums.begin(), nums.end()); // time complexity: O(NlogN)
        int j = 0;
        long long prefix = 0;
        for(int i = 0; i < n; i++){ // sliding window time complexity: O(N)
            while((long long)(i - j) * nums[i] > prefix + k){
                prefix -= nums[j];
                j++;
            }
            ans = max(ans, i - j + 1);
            prefix += nums[i];
        }
        return ans;
    }
};