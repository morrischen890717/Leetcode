class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long good = 0;
        int n = nums.size();
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++){
            int diff = i - nums[i];
            if(cnt.count(diff))
                good += cnt[diff];
            cnt[diff]++;
        }
        return (long long)n * (n - 1) / 2 - good;
    }
};