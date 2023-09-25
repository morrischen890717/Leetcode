class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);
        for(char c: s){
            cnt[c - 'a']++;
        }
        for(char c: t){
            cnt[c - 'a']--;
            if(cnt[c - 'a'] < 0)
                return c;
        }
        return '.';
    }
};