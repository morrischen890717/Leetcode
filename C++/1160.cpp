class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        vector<int> cnt(26, 0);
        for(char c: chars){
            cnt[c - 'a']++;
        }
        for(string& word: words){
            vector<int> tmp(cnt);
            bool isGood = true;
            for(char c: word){
                tmp[c - 'a']--;
                if(tmp[c - 'a'] < 0){
                    isGood = false;
                    break;
                }
            }
            if(isGood)
                ans += word.length();
        }
        return ans;
    }
};