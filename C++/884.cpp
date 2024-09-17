class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> m;
        s1 += ' ';
        s2 += ' ';
        string cur;
        for(char c: s1){
            if(c == ' '){
                m[cur]++;
                cur = "";
            }
            else
                cur += c;
        }
        for(char c: s2){
            if(c == ' '){
                if(m.count(cur))
                    m[cur] = -1;
                else
                    m[cur]++;
                cur = "";
            }
            else
                cur += c;
        }
        for(unordered_map<string, int>::iterator it = m.begin(); it != m.end(); it++){
            if(it->second == 1)
                ans.push_back(it->first);
        }
        return ans;
    }
};