class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int len = s1.length();
        int ptr = -1;
        for(int i = 0; i < len; i++){
            if(s1[i] == s2[i])
                continue;
            else if(ptr == -1)
                ptr = i;
            else if(ptr >= 0 && s1[i] == s2[ptr] && s1[ptr] == s2[i])
                ptr = -2;
            else
                return false;
        }
        return ptr < 0;
    }
};