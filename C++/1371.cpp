class Solution {
public:
    int findTheLongestSubstring(string s) {
        // using unordered_map and prefix sum
        // time complexity: O(N)
        // reference: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/solutions/531840/java-c-python-one-pass/
        int ans = 0;
        int len = s.length();
        unordered_map<int, int> first;
        int cur = 0;
        first[0] = -1;
        for(int i = 0; i < len; i++){
            cur ^= ((1 << (string("aeiou").find(s[i]) + 1)) >> 1);
            if(first.count(cur) == 0)
                first[cur] = i;
            ans = max(ans, i - first[cur]);
        }
        return ans;
    }
};