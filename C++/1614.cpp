class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int len = s.length();
        int cnt = 0;
        for(char c: s){
            if(c == '(')
                cnt++;
            else if(c == ')')
                cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};