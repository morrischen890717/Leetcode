class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        // using prefix sum
        /*
        reference:
        https://leetcode.com/problems/count-of-interesting-subarrays/solutions/3994985/java-c-python-prefix-o-n/?envType=daily-question&envId=2025-04-25
        https://imgur.com/a/VD5h1RY
        */
        long long ans = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int prefix = 0;
        for(int num: nums){
            prefix = (prefix + (num % modulo == k ? 1 : 0)) % modulo;
            ans += cnt[(prefix - k + modulo) % modulo];
            cnt[prefix]++;
        }
        return ans;
    }
};