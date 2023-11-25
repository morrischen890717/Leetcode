class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // using prefix sum
        // time complexity: O(N)
        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] += nums[i - 1];
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = (i - 1 >= 0 ? i * (nums[i] - nums[i - 1]) - nums[i - 1] : 0) + (i + 1 < n ? (nums[n - 1] - nums[i]) - (n - i - 1) * (nums[i] - (i - 1 >= 0 ? nums[i - 1] : 0)) : 0);
        }
        return ans;
    }
};