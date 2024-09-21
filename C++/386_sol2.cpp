class Solution {
public:
    void solve(int n, int cur, vector<int>& ans){
        if(cur > n)
            return;
        ans.push_back(cur);
        solve(n, cur * 10, ans);
        if(cur / 10 == (cur + 1) / 10)  // if the most significant digits of cur and (cur+1) are the same
            solve(n, cur + 1, ans);
        return;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        solve(n, 1, v);
        return v;
    }
};