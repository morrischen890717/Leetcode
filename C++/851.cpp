class Solution {
public:
    int dfs(vector<vector<int>>& next, vector<int>& quiet, int i, vector<int>& ans){
        if(ans[i] != -1)
            return ans[i];
        ans[i] = i;
        for(int j: next[i]){
            if(quiet[dfs(next, quiet, j, ans)] < quiet[ans[i]])
                ans[i] = dfs(next, quiet, j, ans);
        }
        return ans[i];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // using DFS + top-down DP + Topological Sort
        int n = quiet.size();
        vector<int> ans(n, -1);
        vector<vector<int>> next(n);
        for(vector<int>& v: richer){
            next[v[1]].push_back(v[0]);
        }
        for(int i = 0; i < n; i++){
            dfs(next, quiet, i, ans);
        }
        return ans;
    }
};