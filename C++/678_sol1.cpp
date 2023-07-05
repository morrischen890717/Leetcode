class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0; // the range of left parenthesis is in [leftMin, leftMax]
        for(char c: s){
            if(c == '('){
                leftMin++;
                leftMax++;
            }
            else if(c == ')'){
                leftMin--;
                leftMax--;
            }
            else if(c == '*'){
                leftMin--; // treat '*' as ')'
                leftMax++; // treat '*' as '('
            }

            if(leftMax < 0)
                return false;
            leftMin = max(leftMin, 0); 
            // leftMin must update every iteration because ')' which appears first can not match with '(' which appears after ')' 
            // e.g. (*)(
        }
        return leftMin == 0;
    }
};