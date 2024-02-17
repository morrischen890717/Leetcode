class Solution {
public:
    bool isPalindrome(string& word){
        int l = 0, r = word.length() - 1;
        while(l <= r && word[l] == word[r]){
            l++;
            r--;
        }
        return r < l;
    }
    string firstPalindrome(vector<string>& words) {
        for(string& word: words){
            if(isPalindrome(word))
                return word;
        }
        return "";
    }
};