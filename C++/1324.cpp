class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> v;
        string word = "";
        int word_len, max_len = 0;
        for(char c: s){
            if(c == ' '){
                v.push_back(word);
                word_len = word.length();
                max_len = max(max_len, word_len);
                word = "";
            }
            else
                word += c;
        }
        v.push_back(word);
        word_len = word.length();
        max_len = max(max_len, word_len);
        vector<string> ans(max_len);
        for(int i = 0; i < max_len; i++){
            int space = 0;
            for(string& w: v){
                if(i < w.length()){
                    while(space){
                        ans[i] += ' ';
                        space--;
                    }
                    ans[i] += w[i];
                }
                else
                    space++;
            }
        }
        return ans;
    }
};