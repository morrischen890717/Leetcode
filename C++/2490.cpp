class Solution {
public:
    bool isCircularSentence(string sentence) {
        char prev = sentence[0];
        for(int i = 0; i < sentence.length(); i++){
            if(sentence[i] == ' '){
                if(sentence[i + 1] != prev)
                    return false;
            }
            else
                prev = sentence[i];
        }
        return sentence[0] == sentence.back();
    }
};