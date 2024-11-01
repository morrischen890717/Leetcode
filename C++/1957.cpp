class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char prev = '.';
        int cnt = 0;
        for(char c: s){
            if(c != prev){
                prev = c;
                cnt = 1;
                ans += c;
            }
            else if(cnt < 2){
                cnt++;
                ans += c;
            }
        }
        return ans;
    }
};