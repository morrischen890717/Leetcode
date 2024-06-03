class Solution {
public:
    int appendCharacters(string s, string t) {
        // using two-pointers
        int s_len = s.length(), t_len = t.length();
        int j = 0;
        for(int i = 0; i < s_len && j < t_len; i++){
            if(s[i] == t[j])
                j++;
        }
        return t_len - j;
    }
};