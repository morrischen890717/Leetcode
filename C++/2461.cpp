class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int, int> m;
        int l = 0;
        long long sum = 0;
        for(int r = 0; r < n; r++){
            while(m.count(nums[r]) && m[nums[r]] > 0){
                sum -= nums[l];
                m[nums[l]]--;
                l++;
            }
            sum += nums[r];
            m[nums[r]]++;
            if(r - l + 1 == k){
                ans = max(ans, sum);
                sum -= nums[l];
                m[nums[l]]--;
                l++;
            }
        }
        return ans;
    }
};