class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int f = 0;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            f += (i * nums[i]);
        }
        for(int i = n - 1; i >= 0; i--){
            f -= (n - 1) * nums[i];
            f += (sum - nums[i]);
            ans = max(ans, f);
        }
        return ans;
    }
};