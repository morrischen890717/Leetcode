class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int len = s.length();
        int num_1 = 0;
        for(char c: s){
            if(c == '1')
                num_1++;
        }
        for(int i = 0; i < len - 1; i++){
            s[i] = i < num_1 - 1 ? '1' : '0';
        }
        s[len - 1] = '1';
        return s;
    }
};