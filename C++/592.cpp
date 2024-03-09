class Solution {
public:
    pair<int, int> calculate(int numerator1, int denominator1, int numerator2, int denominator2, int sign){
        int gcd_num = gcd(denominator1, denominator2);
        pair<int, int> res = {numerator1 * denominator2 / gcd_num + sign * numerator2 * denominator1 / gcd_num, denominator1 * denominator2 / gcd_num};
        return res;
    }
    string fractionAddition(string expression) {
        expression += '+';
        int len = expression.length();
        int sign = 1;
        pair<int, int> ans = {0, 1}, cur = {0, 1};
        bool isNumerator = true;
        for(int i = 0; i < len; i++){
            if(expression[i] == '-' || expression[i] == '+'){
                ans = calculate(ans.first, ans.second, cur.first, cur.second, sign);
                sign = expression[i] == '+' ? 1 : -1;
                isNumerator = true;
                cur.first = 0;
            }
            else if(expression[i] == '/'){
                isNumerator = false;
                cur.second = 0;
            }
            else if(isNumerator)
                cur.first = cur.first * 10 + (expression[i] - '0');
            else
                cur.second = cur.second * 10 + (expression[i] - '0');
        }
        int gcd_num = gcd(ans.first, ans.second);
        if(ans.first == 0)
            return "0/1";
        return to_string(ans.first / gcd_num) + "/" + to_string(ans.second / gcd_num);
    }
};