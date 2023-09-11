class Solution {
public:
    bool isPalindrome(string s) {
        // using two-pointers
        int len = s.length();
        int l = 0, r = len - 1;
        while(l <= r){
            while(l < len && !isalpha(s[l]) && !isdigit(s[l])){
                l++;
            }
            while(r >= 0 && !isalpha(s[r]) && !isdigit(s[r])){
                r--;
            }
            if(l <= r && tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};