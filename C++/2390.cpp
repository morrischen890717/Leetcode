class Solution {
public:
    string removeStars(string s) {
        string result = "";
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(s[i] == '*')
                result.pop_back();
            else
                result += s[i];
        }
        return result;
    }
};