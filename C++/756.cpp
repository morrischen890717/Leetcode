class Solution {
public:
    bool getUpper(string& bottom, int i, unordered_map<string, vector<char>>& m, string& upper){
        if(i == bottom.size() - 1)
            return solve(m, upper); // go to upper level
        for(char c: m[bottom.substr(i, 2)]){
            upper += c;
            if(getUpper(bottom, i + 1, m, upper))
                return true;
            upper.pop_back();
        }
        return false;
    }
    bool solve(unordered_map<string, vector<char>>& m, string& bottom){
        int len = bottom.length();
        if(len == 1)
            return true;
        for(int i = 0; i < len - 1; i++){
            if(m.count(bottom.substr(i, 2)) == 0)
                return false;
        }
        string upper = "";
        return getUpper(bottom, 0, m, upper);
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = allowed.size();
        unordered_map<string, vector<char>> m;
        for(string& allow: allowed){
            string s = allow.substr(0, 2);
            m[s].push_back(allow[2]);
        }
        return solve(m, bottom);
    }
};