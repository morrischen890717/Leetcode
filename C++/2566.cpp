class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string ss = s;
        char leading = '.';
        for(char& c: ss){
            if(c == '9')
                continue;
            else if(leading == '.'){
                leading = c;
                c = '9';
            }
            else if(c == leading)
                c = '9';
        }
        int max_num = stoi(ss);
        leading = s[0];
        for(char& c: s){
            if(c == leading)
                c = '0';
        }
        int min_num = stoi(s);
        return max_num - min_num;
    }
};