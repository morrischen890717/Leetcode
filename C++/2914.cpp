class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        int len = s.length();
        for(int i = 0; i < len; i += 2){
            if(s[i] != s[i + 1])
                ans++;
        }
        return ans;
    }
};