class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int n = nums.size();
        int l = 0;
        int cur = 0;
        vector<int> cnt(32, 0);
        for(int r = 0; r < n; r++){
            cur |= nums[r];
            for(int i = 0; i < 32; i++){
                if(nums[r] & (1 << i))
                    cnt[i]++;
            }
            while(l <= r && cur >= k){
                ans = min(ans, r - l + 1);
                for(int i = 0; i < 32; i++){
                    if(nums[l] & (1 << i)){
                        cnt[i]--;
                        if(cnt[i] == 0)
                            cur ^= (1 << i);
                    }
                }
                l++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};