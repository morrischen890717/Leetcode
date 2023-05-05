class Solution {
public:
    bool is_vowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int maxVowels(string s, int k) {
        int len = s.length();
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < len; i++){
            cnt += (is_vowel(s[i]) ? 1 : 0);
            if(i >= k)
                cnt -= (is_vowel(s[i - k]) ? 1 : 0);
            ans = max(ans, cnt);
        }
        return ans;
    }
};