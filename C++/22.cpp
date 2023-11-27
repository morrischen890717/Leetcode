class Solution {
public:
    void solve(string& cur, int n, int left, int right, vector<string>& ans){
        if(cur.length() == 2 * n){
            ans.push_back(cur);
            return;
        }
        if(left < n){
            cur += '(';
            solve(cur, n, left + 1, right, ans);
            cur.pop_back();
        }
        if(right < left){
            cur += ')';
            solve(cur, n, left, right + 1, ans);
            cur.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";
        solve(cur, n, 0, 0, ans);
        return ans;
    }
};