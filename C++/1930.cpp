class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // using unordered_set
        // reference: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/solutions/1330165/leftmost-rightmost-and-in-between/?envType=daily-question&envId=2023-11-14
        int ans = 0;
        int len = s.length();
        vector<int> first(26, -1), last(26, -1);
        for(int i = 0; i < len; i++){
            if(first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        for(int i = 0; i < 26; i++){
            if(first[i] == last[i])
                continue;
            unordered_set<char> ss(s.begin() + first[i] + 1, s.begin() + last[i]);
            ans += ss.size();
        }
        return ans;
    }
};