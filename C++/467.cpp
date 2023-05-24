class Solution {
public:
    int findSubstringInWraproundString(string s) {
        /*
        using DP
        reference: https://leetcode.com/problems/unique-substrings-in-wraparound-string/solutions/95439/concise-java-solution-using-dp/
        */
        int len = s.length();
        const int num = 26;
        vector<int> cnt(num, 0); // cnt[i] represents the max length of string which ends with char ('a' + i)
        int curLength = 0;
        int ans = 0;
        int last;
        for(int i = 1; i <= len; i++){
            int cur = s[i - 1] - 'a';
            if((last + 1) % num != cur)
                curLength = 0;
            curLength++;
            last = cur;
            cnt[cur] = max(cnt[cur], curLength);
        }
        for(int i = 0; i < num; i++){
            ans += cnt[i];
        }
        return ans;
    }
};