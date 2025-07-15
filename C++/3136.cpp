class Solution {
public:
    bool isValid(string word) {
        int len = word.length();
        if(len < 3)
            return false;
        bool vowel = false, consonant = false;
        for(char c: word){
            if(!isalpha(c) && !isdigit(c))
                return false;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                vowel = true;
            else if(isalpha(c))
                consonant = true;
        }
        return vowel && consonant;
    }
};