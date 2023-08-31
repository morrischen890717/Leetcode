class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        /*
        using prefix sum
        time complexity: O(N), space complexity: O(K)
        reference:
        https://leetcode.com/problems/subarray-sums-divisible-by-k/solutions/217985/java-c-python-prefix-sum/
        https://imgur.com/a/0TqK7eo
        */
        int ans = 0;
        int prefix = 0;
        vector<int> prefixSum(k, 0);
        prefixSum[0] = 1;
        for(int num: nums){
            prefix = ((prefix + num) % k + k) % k;
            ans += prefixSum[prefix];
            prefixSum[prefix]++;
        }
        return ans;
    }
};