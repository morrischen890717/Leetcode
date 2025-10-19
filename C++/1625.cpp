class Solution {
public:
    string addStr(string s, int a){
        int len = s.length();
        for(int i = 1; i < len; i += 2){
            s[i] = '0' + (s[i] + a - '0') % 10;
        }
        return s;
    }
    string rotate(string s, int b){
        int len = s.length();
        string res;
        for(int i = 0; i < len; i++){
            res += s[(len - b + i) % len];
        }
        return res;
    }
    void solve(string& s, int a, int b, unordered_set<string>& ss, string& ans){
        if(ss.count(s))
            return;
        else{
            ans = min(ans, s);
            ss.insert(s);
        }
        string addS = addStr(s, a);
        solve(addS, a, b, ss, ans);
        string rotateS = rotate(s, b);
        solve(rotateS, a, b, ss, ans);
        return;
    }
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> ss;
        string ans = s;
        solve(s, a, b, ss, ans);
        return ans;
    }
};