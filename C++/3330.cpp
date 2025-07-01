class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 0, cnt = 1;
        char prev = '.';
        for(char c: word){
            if(c == prev)
                cnt++;
            else{
                ans += cnt - 1;
                cnt = 1;
                prev = c;
            }
        }
        ans += cnt;
        return ans;
    }
};