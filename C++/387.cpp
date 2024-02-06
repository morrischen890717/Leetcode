class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length();
        vector<int> cnt(26, 0);
        for(char c: s){
            cnt[c - 'a']++;
        }
        for(int i = 0; i < len; i++){
            if(cnt[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};