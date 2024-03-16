class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // using unordered_map
        // time complexity: O(N), space complexity: O(N)
        int ans = 0;
        unordered_map<int, int> cnt;
        int prefix = 0;
        cnt[prefix] = 1;
        for(int num: nums){
            prefix += num;
            if(cnt.count(prefix - goal))
                ans += cnt[prefix - goal];
            cnt[prefix]++;
        }
        return ans;
    }
};