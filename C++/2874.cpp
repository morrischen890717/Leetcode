class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> v(n + 1, 0);
        for(int i = n - 1; i >= 0; i--){
            v[i] = max(v[i + 1], nums[i]);
        }
        int max_val = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] < max_val)
                ans = max(ans, (long long)(max_val - nums[i]) * v[i + 1]);
            max_val = max(max_val, nums[i]);
        }
        return ans;
    }
};