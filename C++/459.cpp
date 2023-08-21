class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // using KMP Algorithm
        // reference: https://leetcode.com/problems/repeated-substring-pattern/solutions/94397/c-o-n-using-kmp-32ms-8-lines-of-code-with-brief-explanation/
        int len = s.length();
        vector<int> next(len + 1, -1);
        int j = -1;
        for(int i = 1; i <= len; i++){
            while(j >= 0 && s[i - 1] != s[j]){
                j = next[j];
            }
            j++;
            next[i] = j;
        }
        return next[len] && next[len] % (len - next[len]) == 0;
    }
};