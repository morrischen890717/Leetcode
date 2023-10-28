class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.length();
        for(int i = 0; i < len; i++){
            if(palindrome[i] != 'a' && !(len % 2 && i == len / 2)){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        if(len == 1)
            return "";
        palindrome[len - 1] = 'b';
        return palindrome;
    }
};