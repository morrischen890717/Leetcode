class Solution {
public:
    int extend(string& s, int len, int i, int j){
        int num = 0;
        while(i >= 0 && j < len && s[i] == s[j]){
            num++;
            i--;
            j++;
        }
        return num;
    }
    int countSubstrings(string s) {
        int len = s.length();
        int ans = 0;
        for(int i = 0; i < len; i++){
            ans += extend(s, len, i, i);
            ans += extend(s, len, i, i + 1);
        }
        return ans;
    }
};