class Solution {
public:
    string maskPII(string s) {
        int len = s.length();
        string ans;
        bool isPhone = isdigit(s.back()) || s.back() == ' ' || s.back() == '(' || s.back() == ')' || s.back() == '-' || s.back() == '+' ? true : false;
        if(isPhone){
            int digitCnt = 0;
            for(int i = len - 1; i >= 0; i--){
                if(isdigit(s[i])){
                    digitCnt++;
                    if(ans.length() < 4)
                        ans = s[i] + ans;
                }
            }
            ans = "***-***-" + ans;
            if(digitCnt > 10)
                ans = "-" + ans;
            for(int i = 10; i < digitCnt; i++){
                ans = "*" + ans;
            }
            if(digitCnt > 10)
                ans = "+" + ans;
        }
        else{
            bool domain = false;
            for(int i = 1; i < len; i++){
                if(domain)
                    ans += tolower(s[i]);
                else if(s[i] == '@'){
                    domain = true;
                    ans += tolower(s[0]);
                    if(i > 1){
                        ans += "*****";
                        ans += tolower(s[i - 1]);
                    }
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};