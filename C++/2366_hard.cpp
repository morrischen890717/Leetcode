class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        // using Greedy
        // time complexity: O(N), space complexity: O(1)
        long long ans = 0;
        int n = nums.size();
        int minVal = INT_MAX;
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] <= minVal){
                minVal = nums[i];
                continue;
            }
            int split = (nums[i] / minVal) + (nums[i] % minVal ? 1 : 0); // # of pieces that we shoulf split nums[i] into
            ans += (split - 1);
            minVal = nums[i] / split;
        }
        return ans;
    }
};