class Solution {
public:
    string reverseOnlyLetters(string s) {
        // using two-pointers
        // time complexity: O(N), space complexity: O(1)
        int l = 0, r = s.length() - 1;
        while(l < r){
            while(l < r && !isalpha(s[l])){
                l++;
            }
            while(l < r && !isalpha(s[r])){
                r--;
            }
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};