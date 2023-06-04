class Solution {
public:
    int minimizedStringLength(string s) {
        int len = s.length();
        vector<bool> appear(26, false);
        int cnt = 0;
        for(char c: s){
            if(!appear[c - 'a']){
                cnt++;
                appear[c - 'a'] = true;
            }
        }
        return cnt;
    }
};