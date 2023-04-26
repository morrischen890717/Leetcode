class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
        while(s.length() > 1){
            int result = 0;
            for(int i = 0; i < s.length(); i++){
                result += (s[i] - '0');
            }
            s = to_string(result);
        }
        return stoi(s);
    }
};