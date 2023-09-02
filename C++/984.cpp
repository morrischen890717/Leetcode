class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s;
        while(a || b){
            if(a > b){
                if(s.length() >= 2 && s[s.length() - 1] == 'a' && s[s.length() - 2] == 'a'){
                    s += 'b';
                    b--;
                }
                else{
                    s += 'a';
                    a--;
                }
            }
            else{
                if(s.length() >= 2 && s[s.length() - 1] == 'b' && s[s.length() - 2] == 'b'){
                    s += 'a';
                    a--;
                }
                else{
                    s += 'b';
                    b--;
                }
            }
        }
        return s;
    }
};