class Solution {
public:
    string add(string s1, string s2){
        string res;
        int len1 = s1.length(), len2 = s2.length(), carry = 0;
        while(len1 > 0 || len2 > 0 || carry > 0){
            int num1 = len1 > 0 ? s1[len1 - 1] - '0' : 0, num2 = len2 > 0 ? s2[len2 - 1] - '0' : 0;
            carry += (num1 + num2);
            res += ('0' + carry % 10);
            carry /= 10;
            len1--;
            len2--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool solve(string s1, string s2, string remain){
        int len1 = s1.length(), len2 = s2.length();
        if(len1 >= 2 && s1[0] == '0' || len2 >= 2 && s2[0] == '0')
            return false;
        string res = add(s1, s2);
        if(remain == res)
            return true;
        if(remain.length() < res.length() || res != remain.substr(0, res.length()))
            return false;
        return solve(s2, res, remain.substr(res.length()));
    }
    bool isAdditiveNumber(string num) {
        int len = num.length();
        for(int i = 1; i <= len / 2; i++){
            for(int j = 1; j <= (len - i) / 2; j++){
                if(solve(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
                    return true;
            }
        }
        return false;
    }
};