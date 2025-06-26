class Solution {
public:
    int longestSubsequence(string s, int k) {
        // using Greedy
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/solutions/2168227/java-c-python-one-pass-o-n/?envType=daily-question&envId=2025-06-26
        int res = 0, j = 1;
        int len = s.length();
        for(int i = len - 1; i >= 0; i--){
            if(s[i] == '0' || j <= k){
                res++;
                k -= (s[i] - '0') * j;
            }
            if(j <= k)
                j *= 2;
        }
        return res;
    }
};