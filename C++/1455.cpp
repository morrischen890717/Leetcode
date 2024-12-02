class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        bool valid = true;
        int id = 0, cnt = 1;
        for(int i = 0; i < sentence.length(); i++){
            if(sentence[i] == ' '){
                valid = true;
                cnt++;
                id = 0;
            }
            else if(valid){
                if(sentence[i] == searchWord[id]){
                    id++;
                    if(id == searchWord.length())
                        return cnt;
                }
                else
                    valid = false;
            }
        }
        return -1;
    }
};