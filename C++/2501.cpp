class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        unordered_map<long long, int> m;
        sort(nums.begin(), nums.end());
        for(int i = n - 1; i >= 0; i--){
            long long target = (long long)nums[i] * nums[i];
            if(m.count(target)){
                m[nums[i]] = m[target] + 1;
                ans = max(ans, m[nums[i]]);
            }
            else
                m[nums[i]] = 1;
        }
        return ans;
    }
};