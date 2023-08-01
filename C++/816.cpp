class Solution {
public:
    vector<string> solve(string& s){
        if(stoi(s) == 0){
            if(s == "0")
                return {s};
            return {};
        }
        vector<string> res;
        if(s[0] != '0')
            res.push_back(s);
        int len = s[0] == '0' ? 2 : s.length();
        for(int i = 1; i < len; i++){
            string right = s.substr(i);
            if(right.back() != '0')
                res.push_back(s.substr(0, i) + "." + right);
            else
                break;
        }
        return res;
    }
    vector<string> ambiguousCoordinates(string s) {
        // using backtrack and substr()
        vector<string> ans;
        int len = s.length();
        for(int i = 1; i < len - 2; i++){
            string left = s.substr(1, i);
            string right = s.substr(i + 1, len - 2 - i);
            vector<string> resLeft = solve(left);
            vector<string> resRight = solve(right);
            for(string& l: resLeft){
                for(string& r: resRight){
                    ans.push_back("(" + l + ", " + r + ")");
                }
            }
        }
        return ans;
    }
};