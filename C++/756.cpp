class Solution {
public:
    bool solve(unordered_map<string, vector<char>>& m, string& bottom, string& s, int i){
        if(i == bottom.size() - 1)
            return dfs(m, s);
        string base = bottom.substr(i, 2);
        if(m.count(base) == 0)
            return false;
        for(char c: m[base]){
            s += c;
            if(solve(m, bottom, s, i + 1))
                return true;
            s.pop_back();
        }
        return false;
    }
    bool dfs(unordered_map<string, vector<char>>& m, string& bottom){
        int len = bottom.length();
        if(len == 1)
            return true;
        string s = "";
        return solve(m, bottom, s, 0);
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> m;
        for(string& allow: allowed){
            m[allow.substr(0, 2)].push_back(allow[2]);
        }
        return dfs(m, bottom);
    }
};