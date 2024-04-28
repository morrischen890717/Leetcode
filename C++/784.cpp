class Solution {
public:
    void addChar(string& s, string& cur, int i, char c, vector<string>& ans){
        cur += c;
        solve(s, cur, i + 1, ans);
        cur.pop_back();
        return;
    }
    void solve(string& s, string& cur, int i, vector<string>& ans){
        if(i == s.length()){
            ans.push_back(cur);
            return;
        }
        addChar(s, cur, i, s[i], ans);
        if(isupper(s[i]))
            addChar(s, cur, i, tolower(s[i]), ans);
        else if(islower(s[i]))
            addChar(s, cur, i, toupper(s[i]), ans);
        return;
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string cur = "";
        solve(s, cur, 0, ans);
        return ans;
    }
};