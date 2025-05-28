class Solution {
public:
    int dfs(vector<vector<int>>& graph, int i, int prev, int k){
        if(k < 0)
            return 0;
        int cnt = 1;
        for(int next: graph[i]){
            if(next == prev)
                continue;
            cnt += dfs(graph, next, i, k - 1);
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // using DFS
        // reference: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/solutions/6788282/using-dfs-with-images-example-walkthrough-c-python-java/?envType=daily-question&envId=2025-05-28
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> graph1(n), graph2(m);
        for(vector<int>& edge: edges1){
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        for(vector<int>& edge: edges2){
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }
        int max_cnt = 0;
        for(int i = 0; i < m; i++){
            max_cnt = max(max_cnt, dfs(graph2, i, -1, k - 1));
        }
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            ans[i] = dfs(graph1, i, -1, k) + max_cnt;
        }
        return ans;
    }
};