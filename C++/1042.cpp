class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& m, int cur, int pre_type, vector<int>& ans){
        if(ans[cur] == pre_type)
            return false;
        else if(ans[cur])
            return true;
        for(int t = 1; t <= 4; t++){
            if(t == pre_type)
                continue;
            bool valid = true;
            ans[cur] = t;
            for(int next: m[cur]){
                if(!dfs(m, next, t, ans)){
                    valid = false;
                    break;
                }
            }
            if(valid)
                return true;
            ans[cur] = 0;
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // using DFS
        vector<int> ans(n, 0);
        unordered_map<int, vector<int>> m;
        for(vector<int>& path: paths){
            m[path[0] - 1].push_back(path[1] - 1);
            m[path[1] - 1].push_back(path[0] - 1);
        }
        for(int i = 0; i < n; i++){
            dfs(m, i, -1, ans);
        }
        return ans;
    }
};