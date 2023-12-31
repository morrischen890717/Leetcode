class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        vector<int> pos(26, -1);
        for(int i = 0; i < s.length(); i++){
            if(pos[s[i] - 'a'] == -1)
                pos[s[i] - 'a'] = i;
            else
                ans = max(ans, i - pos[s[i] - 'a'] - 1);
        }
        return ans;
    }
};