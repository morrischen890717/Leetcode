class Solution {
public:
    int minimumLength(string s) {
        // using two-pointers
        // time complexity: O(N), space complexity: O(1)
        int len = s.length();
        int l = 0, r = len - 1;
        while(l <= r){
            char l_char = s[l], r_char = s[r];
            if(l == r || l_char != r_char)
                break;
            while(l < len && s[l] == l_char){
                l++;
            }
            while(r >= 0 && s[r] == r_char){
                r--;
            }
        }
        return l <= r ? r - l + 1 : 0;
    }
};