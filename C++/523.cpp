class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        /*
        time complexity: O(N), space complexity: O(k)
        reference: https://leetcode.com/problems/continuous-subarray-sum/solutions/99499/java-o-n-time-o-k-space/
        */
        int n = nums.size();
        unordered_map<int, int> m; // key-value: remainder-index
        m[0] = -1; // for the remainder of 0
        int prefix = 0;
        for(int i = 0; i < n; i++){
            prefix += nums[i];
            prefix %= k;
            if(m.count(prefix) > 0){ // nums[m[prefix] + 1] + ... + nums[i] will be a multiple of k
                if(i - m[prefix] > 1) // length should be at least two
                    return true;
            }
            else
                m[prefix] = i;
        }
        return false;
    }
};