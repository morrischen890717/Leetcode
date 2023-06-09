class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(prefix.count(sum - k) > 0)
                ans += prefix[sum - k];
            prefix[sum]++;
        }
        return ans;
    }
};