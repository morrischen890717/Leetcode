class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if(n < 2 * k + 1)
            return ans;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(i >= 2 * k){
                ans[i - k] = sum / (2 * k + 1);
                sum -= nums[i - 2 * k];
            }
        }
        return ans;
    }
};