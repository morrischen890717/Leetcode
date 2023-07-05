class Solution {
public:
    bool checkValidString(string s) {
        int len = s.length();
        int left = 0;
        int star = 0;
        for(int i = 0; i < len; i++){ // from left to right
            if(s[i] == ')'){
                if(left > 0)
                    left--;
                else if(star > 0)
                    star--;
                else
                    return false;
            }
            else if(s[i] == '(')
                left++;
            else if(s[i] == '*')
                star++;
        }
        if(left > star)
            return false;

        int right = 0;
        star = 0;
        for(int i = len - 1; i >= 0; i--){ // from right to left
            if(s[i] == '('){
                if(right > 0)
                    right--;
                else if(star > 0)
                    star--;
                else
                    return false;
            }
            else if(s[i] == ')')
                right++;
            else if(s[i] == '*')
                star++;
        }
        if(right > star)
            return false;
        return true;
    }
};