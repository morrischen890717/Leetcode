class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // using unordered_map and unordered_set
        int len = s.length();
        unordered_map<char, char> m;
        unordered_set<char> visited;
        for(int i = 0; i < len; i++){
            if(visited.count(t[i]) && m.count(s[i]) && m[s[i]] == t[i] || !visited.count(t[i]) && !m.count(s[i])){
                m[s[i]] = t[i];
                visited.insert(t[i]);
            }
            else
                return false;
        }
        return true;
    }
};