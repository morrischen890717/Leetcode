class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<int, int> m;
        string ans;
        long long remainder = (long long)numerator;
        int cur = 0;
        if((remainder < 0 && denominator > 0) || (remainder > 0 && denominator < 0))
            ans += "-";
        remainder = abs(remainder);
        denominator = abs(denominator);
        ans += to_string(remainder / denominator);
        remainder %= denominator;
        if(remainder){
            ans += ".";
            cur = ans.length();
            m[remainder] = cur;
            cur++;
            remainder *= 10;
        }
        while(remainder){
            ans += to_string(remainder / denominator);
            remainder %= denominator;
            if(m.count(remainder) > 0){
                ans.insert(m[remainder], "(");
                ans += ")";
                break;
            }
            m[remainder] = cur;
            cur++;
            remainder *= 10;
        }
        return ans;
    }
};