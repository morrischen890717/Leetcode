class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // using two-pointers
        // time complexity: O(N), space complexity: O(N)
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> cnt;
        int l = 0;
        for(int r = 0; r < n; r++){
            cnt[nums[r]]++;
            while(l <= r && cnt[nums[r]] > k){
                cnt[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};