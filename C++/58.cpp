class Solution {
public:
    int lengthOfLastWord(string s) {
        bool new_word = true;
        int cnt = 0;
        for(char c: s){
            if(c == ' ')
                new_word = true;
            else{
                if(new_word){
                    new_word = false;
                    cnt = 0;
                }
                cnt++;
            }
        }
        return cnt;
    }
};