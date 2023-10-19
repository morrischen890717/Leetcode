class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // using two-pointers
        int ptr_s = s.length() - 1, ptr_t = t.length() - 1;
        while(ptr_s >= 0 || ptr_t >= 0){
            int cnt_s = 0, cnt_t = 0;
            while(ptr_s >= 0 && (cnt_s > 0 || s[ptr_s] == '#')){
                cnt_s += s[ptr_s] == '#' ? 1 : -1;
                ptr_s--;
            }
            while(ptr_t >= 0 && (cnt_t > 0 || t[ptr_t] == '#')){
                cnt_t += t[ptr_t] == '#' ? 1 : -1;
                ptr_t--;
            }
            char char_s = ptr_s >= 0 ? s[ptr_s] : '.';
            char char_t = ptr_t >= 0 ? t[ptr_t] : '.';
            if(char_s == '#' || char_t == '#')
                continue;
            if(char_s != char_t)
                return false;
            ptr_s--;
            ptr_t--;
        }
        return true;
    }
};