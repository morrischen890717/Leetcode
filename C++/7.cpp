class Solution {
public:
    void remove_leading_zero(string& s, int sign){
        int pos = (sign == 1 ? 0 : 1);
        while(pos < s.length() - 1 && s[pos] == '0'){
            s.erase(s.begin() + pos);
        }
        return;
    }
    bool check_valid(string s, int sign){
        string cmp = (sign == 1 ? to_string(INT_MAX) : to_string(INT_MIN));
        int cmplen = cmp.length();
        int len = s.length();
        if(len > cmplen)
            return false;
        else if(len < cmplen)
            return true;
        int id = 0;
        while(id < len){
            if(s[id] < cmp[id])
                return true;
            else if(s[id] > cmp[id])
                return false;
            id++;
        }
        return true;
    }
    int reverse(int x) {
        int sign = (x >= 0 ? 1 : -1);
        string str = to_string(x);
        if(sign == 1)
            std::reverse(str.begin(), str.end());
        else
            std::reverse(str.begin() + 1, str.end());
        remove_leading_zero(str, sign);
        return check_valid(str, sign) ? stoi(str) : 0;
    }
};