class Solution {
public:
    bool dfs(string& pattern, string& cur, int state){
        int len = cur.length();
        if(len == pattern.length() + 1)
            return true;
        char last = cur.back();
        if(pattern[len - 1] == 'I'){
            for(int i = last - '0' + 1; i <= 9; i++){
                if((state & (1 << i)) == 0){
                    cur += '0' + i;
                    if(dfs(pattern, cur, state | (1 << i)))
                        return true;
                    cur.pop_back();
                }
            }
        }
        else{
            for(int i = 1; i < last - '0'; i++){
                if((state & (1 << i)) == 0){
                    cur += '0' + i;
                    if(dfs(pattern, cur, state | (1 << i)))
                        return true;
                    cur.pop_back();
                }
            }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        for(int i = 1; i <= 9; i++){
            string s = to_string(i);
            if(dfs(pattern, s, 1 << i))
                return s;
        }
        return "";
    }
};