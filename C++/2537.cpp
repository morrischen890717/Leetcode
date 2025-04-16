class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        // using unordered_map and sliding window
        long long ans = 0;
        unordered_map<int, int> cnt;
        int n = nums.size();
        int l = 0;
        int pairs = 0;
        for(int r = 0; r < n; r++){
            pairs += cnt[nums[r]]++;
            while(pairs >= k){
                ans += n - r;
                pairs -= --cnt[nums[l++]];
            }
        }
        return ans;
    }
};