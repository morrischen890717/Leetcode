class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int len = s.length();
        vector<int> pos(3, -1);
        for(int i = 0; i < len; i++){
            pos[s[i] - 'a'] = i;
            ans += (min({pos[0], pos[1], pos[2]}) + 1);
        }
        return ans;
    }
};