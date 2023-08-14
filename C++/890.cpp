class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int len = pattern.size();
        for(string& word: words){
            vector<char> replace(26, 127); // word to pattern
            vector<bool> used(26, false); // pattern to word (if this char is used or not)
            bool canReplace = true;
            for(int i = 0; i < len; i++){
                if(replace[word[i] - 'a'] == 127){
                    if(used[pattern[i] - 'a']){
                        canReplace = false;
                        break;
                    }
                    replace[word[i] - 'a'] = pattern[i];
                    used[pattern[i] - 'a'] = true;
                }
                else if(replace[word[i] - 'a'] != pattern[i]){
                    canReplace = false;
                    break;
                }
            }
            if(canReplace)
                ans.push_back(word);
        }
        return ans;
    }
};