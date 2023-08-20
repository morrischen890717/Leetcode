class Solution {
public:
    int minAddToMakeValid(string s) {
        int cntLeft = 0, cntRight = 0;
        for(char c: s){
            if(c == '(')
                cntLeft++;
            else if(cntLeft > 0)
                cntLeft--;
            else
                cntRight++;
        }
        return cntLeft + cntRight;
    }
};