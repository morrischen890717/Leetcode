class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // using prefix sum and unordered_map
        // time complexity: O(N), space complexity: O(N)
        int n = nums.size();
        int ans = 0, prefix = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for(int i = 0; i < n; i++){
            prefix += nums[i];
            if(cnt.count(prefix - k))
                ans += cnt[prefix - k];
            cnt[prefix]++;
        }
        return ans;
    }
};