class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        int len = pref.length();
        for(string& word: words){
            if(word.length() < len)
                continue;
            bool valid = true;
            for(int i = 0; i < len; i++){
                if(word[i] != pref[i]){
                    valid = false;
                    break;
                }
            }
            if(valid)
                cnt++;
        }
        return cnt;
    }
};