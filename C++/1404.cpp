class Solution {
public:
    int numSteps(string s) {
        int len = s.length();
        bool isOne = len == 1 && s.back() == '1';
        if(len == 1 && s.back() == '1')
            return 0;
        if(s.back() == '1'){
            s.pop_back();
            for(int i = s.length() - 1; i >= 0; i--){
                if(s[i] == '0'){
                    s[i] = '1';
                    break;
                }
                else
                    s[i] = '0';
            }
            if(s[0] == '0')
                s = "1" + s;
            /*
            if num is odd, we will add 1 first and then divide by 2(because num will be even after adding 1), so it takes 2 steps
            (num + 1) / 2 = num / 2 + 1 / 2 = num / 2 + 1 (because num is odd, it would get 0.5 after dividing by 2)
            */
            return 2 + numSteps(s);
        }
        else{
            s.pop_back();
            return 1 + numSteps(s);
        }
        return -1;
    }
};