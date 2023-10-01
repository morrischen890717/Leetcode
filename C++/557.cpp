class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        int start = 0;
        for(int i = 0; i < len; i++){
            if(s[i] == ' '){
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        if(start < len)
            reverse(s.begin() + start, s.end());
        return s;
    }
};