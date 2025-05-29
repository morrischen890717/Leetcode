class Solution {
public:
    int dfs(vector<vector<int>>& graph, vector<int>& color, int i, bool even, int& cnt){
        cnt++;
        color[i] = even ? 1 : 0;
        int even_cnt = even ? 1 : 0;
        for(int next: graph[i]){
            if(color[next] != -1)
                continue;
            even_cnt += dfs(graph, color, next, !even, cnt);
        }
        return even_cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // using DFS
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> graph1(n), graph2(m);
        vector<int> color1(n, -1), color2(m, -1);
        for(vector<int>& edge: edges1){
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        for(vector<int>& edge: edges2){
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }
        int cnt1 = 0, cnt2 = 0;
        int even_cnt1 = dfs(graph1, color1, 0, true, cnt1);
        int even_cnt2 = dfs(graph2, color2, 0, true, cnt2);
        int max_cnt2 = max(even_cnt2, cnt2 - even_cnt2);
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = (color1[i] ? even_cnt1 : cnt1 - even_cnt1) + max_cnt2;
        }
        return ans;
    }
};