class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string sortVowels(string s) {
        vector<char> vowels;
        vector<int> index;
        for(int i = 0; i < s.length(); i++){
            if(isVowel(s[i])){
                vowels.push_back(s[i]);
                index.push_back(i);
            }
        }
        sort(vowels.begin(), vowels.end());
        for(int i = 0; i < vowels.size(); i++){
            s[index[i]] = vowels[i];
        }
        return s;
    }
};