class Solution {
public:
    int cntRepeat(string& s, string& cur){
        if(cur.empty())
            return INT_MAX;
        int i = 0, len = cur.length();
        int cnt = 0;
        for(char c: s){
            if(c == cur[i]){
                i++;
                if(i == len){
                    cnt++;
                    i = 0;
                }
            }
        }
        return cnt;
    }
    void solve(string& s, int k, string& cur, string& ans){
        int cnt = cntRepeat(s, cur);
        if(cnt < k)
            return;
        if(cur.length() > ans.length() || (cur.length() == ans.length()))
            ans = cur;
        for(char c = 'a'; c <= 'z'; c++){
            cur += c;
            solve(s, k, cur, ans);
            cur.pop_back();
        }
        return;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        // reference: https://leetcode.com/problems/longest-subsequence-repeated-k-times/solutions/1472073/easy-to-read-short-25-lines-c-with-comments/?envType=daily-question&envId=2025-06-27
        string ans, cur;
        solve(s, k, cur, ans);
        return ans;
    }
};