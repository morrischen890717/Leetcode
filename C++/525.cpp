class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int prefix = 0;
        unordered_map<int, int> m; // key-value: prefix-index
        m[0] = -1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            prefix += (nums[i] ? 1 : -1); // If nums[i] == 1, then +1. If nums[i] == 0, then -1.
            if(m.count(prefix) > 0) // means that nums[m[prefix]] ~ nums[i] is a contiguous subarray with an equal number of 0 and 1
                ans = max(ans, i - m[prefix]);
            else
                m[prefix] = i;
        }
        return ans;
    }
};