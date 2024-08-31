class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for(char c: s){
            cnt[c - 'a']++;
        }
        for(unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            ans += it->second % 2 ? it->second - 1 : it->second;
        }
        return ans == s.length() ? ans : ans + 1;
    }
};