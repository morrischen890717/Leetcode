class Solution {
public:
    int kmp(string& s){
        string p = string(s.rbegin(), s.rend());
        string new_s = s + "#" + p;
        vector<int> next(new_s.length());
        next[0] = 0;
        int i = 1, k = 0;
        while(i < new_s.length()){
            if(new_s[i] == new_s[k]){
                next[i] = ++k;
                i++;
            }
            else if(k == 0){
                next[i] = 0;
                i++;
            }
            else
                k = next[k - 1];
        }
        return next.back();
    }
    string shortestPalindrome(string s) {
        int cnt = kmp(s);
        return string(s.rbegin(), s.rend()).substr(0, s.length() - cnt) + s;
    }
};