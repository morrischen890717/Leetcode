class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int ans = 0;
        // we pre-calculated the power value so we just need to calculated once
        vector<int> pre_calculate(n);
        pre_calculate[0] = 1;
        for(int i = 1; i < n; i++){
            pre_calculate[i] = ((pre_calculate[i - 1] << 1) % MOD);
        }
        
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        while(l < n){
            while(l <= r && nums[l] + nums[r] > target){
                r--;
            }
            if(l <= r){
                ans += pre_calculate[r - l];
                ans %= MOD;
                l++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};