class Solution {
public:
    void dfs(vector<vector<int>>& graph, int i, vector<int>& cur, vector<vector<int>>& ans){
        cur.push_back(i);
        if(i == graph.size() - 1){
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        for(int next: graph[i]){
            dfs(graph, next, cur, ans);
        }
        cur.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(graph, 0, cur, ans);
        return ans;
    }
};