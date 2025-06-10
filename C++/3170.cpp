class Solution {
public:
    string clearStars(string s) {
        int len = s.length();
        vector<vector<int>> pos(26);
        for(int i = 0; i < len; i++){
            if(s[i] == '*'){
                int j = 0;
                while(j < 26 && pos[j].size() == 0){
                    j++;
                }
                s[pos[j].back()] = '*';
                pos[j].pop_back();
            }
            else
                pos[s[i] - 'a'].push_back(i);
        }
        string ans;
        for(char c: s){
            if(c != '*')
                ans += c;
        }
        return ans;
    }
};