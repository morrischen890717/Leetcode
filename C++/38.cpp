class Solution {
public:
    string convert(string& s){
        int cnt = 0;
        char prev = s[0];
        string res;
        for(char c: s){
            if(c != prev){
                res += (to_string(cnt) + prev);
                prev = c;
                cnt = 0;
            }
            cnt++;
        }
        res += (to_string(cnt) + prev);
        return res;
    }
    string countAndSay(int n) {
        string s = "1";
        for(int i = 1; i < n; i++){
            s = convert(s);
        }
        return s;
    }
};