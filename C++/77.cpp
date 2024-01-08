class Solution {
public:
    void solve(int i, int n, int k, vector<int>& cur, vector<vector<int>>& ans){
        if(cur.size() == k){
            ans.push_back(cur);
            return;
        }
        for(int next = i; next <= n; next++){
            cur.push_back(next);
            solve(next + 1, n, k, cur, ans);
            cur.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        solve(1, n, k, cur, ans);
        return ans;
    }
};