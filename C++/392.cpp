class Solution {
public:
    bool isSubsequence(string s, string t) {
        // using two-pointers
        // time complexity: O(t.length())
        int len = s.length(), ptr = 0;
        for(int i = 0; i < t.length() && ptr < len; i++){
            if(t[i] == s[ptr])
                ptr++;
        }
        return ptr == len;
    }
};