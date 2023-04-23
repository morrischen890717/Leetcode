class Solution {
public:
    int calculate(string s) {  // without using stack/deque
        s += '+';
        int n = s.length();
        int ans = 0, prevnum = 0, currnum = 0;
        char oper = '+';
        for(int i = 0; i < n; i++){
            if(s[i] == ' ')
                continue;
            else if(isdigit(s[i])){
                currnum = currnum * 10 + (s[i] - '0');
            }
            else{
                if(oper == '+' || oper == '-'){
                    ans += prevnum;
                    prevnum = (oper == '+' ? currnum : -currnum);
                }
                else{
                    if(oper == '*')
                        prevnum = prevnum * currnum;
                    else if(oper == '/')
                        prevnum = prevnum / currnum;
                }
                oper = s[i];
                currnum = 0;
            }
        }
        ans += prevnum;
        return ans;
    }
};