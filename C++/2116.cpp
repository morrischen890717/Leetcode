class Solution {
public:
    bool canBeValid(string s, string locked) {
        int len = s.length();
        if(len % 2)
            return false;
        int cnt = 0;
        for(int i = 0; i < len; i++){
            if(locked[i] == '0' || s[i] == '(')
                cnt++;
            else
                cnt--;
            if(cnt < 0)
                return false;
        }
        cnt = 0;
        for(int i = len - 1; i >= 0; i--){
            if(locked[i] == '0' || s[i] == ')')
                cnt++;
            else
                cnt--;
            if(cnt < 0)
                return false;
        }
        return true;
    }
};