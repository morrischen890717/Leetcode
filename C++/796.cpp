class Solution {
public:
    bool isEqual(string& s1, int i, string& s2, int j){
        int len = s1.length();
        for(int k = 0; k < len; k++){
            if(s1[(i + k) % len] != s2[(j + k) % len])
                return false;
        }
        return true;
    }
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        for(int i = 0; i < s.length(); i++){
            if(isEqual(s, i, goal, 0))
                return true;
        }
        return false;
    }
};