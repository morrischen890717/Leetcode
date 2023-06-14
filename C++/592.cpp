class Solution {
public:
    int lcm(int a, int b){ // least common multiple
        return a * b / gcd(a, b);
    }
    string fractionAddition(string expression) {
        int len = expression.length();
        int i = 0;
        vector<int> numerator;
        vector<int> denominator;
        string s = "";
        while(i < len){
            char c = expression[i];
            if(c == '/'){
                numerator.push_back(stoi(s));
                s = "";
            }
            else if(c == '-' || c == '+'){
                if(s != "")
                    denominator.push_back(stoi(s));
                s = (c == '-' ? "-" : "");
            }
            else
                s += c;
            i++;
        }
        denominator.push_back(stoi(s));
        int cur_num = 0, cur_denom = 1;
        for(int j = 0; j < numerator.size(); j++){
            int cur_lcm = lcm(cur_denom, denominator[j]);
            cur_num = cur_num * cur_lcm / cur_denom + numerator[j] * cur_lcm / denominator[j];
            cur_denom = cur_lcm;
            int cur_gcd = gcd(cur_num, cur_denom);
            cur_num /= cur_gcd;
            cur_denom /= cur_gcd;
        }
        return to_string(cur_num) + "/" + to_string(cur_denom);
    }
};