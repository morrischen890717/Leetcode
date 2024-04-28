class Solution {
public:
    void dfs1(vector<vector<int>>& neighbor, vector<int>& cnt, vector<int>& sum, int prev, int cur){
        for(int next: neighbor[cur]){
            if(next == prev)
                continue;
            dfs1(neighbor, cnt, sum, cur, next);
            cnt[cur] += cnt[next];
            sum[cur] += sum[next] + cnt[next];
        }
        return;
    }
    void dfs2(vector<vector<int>>& neighbor, vector<int>& cnt, vector<int>& sum, int prev, int cur){
        for(int next: neighbor[cur]){
            if(next == prev)
                continue;
            sum[next] = sum[cur] - cnt[next] + neighbor.size() - cnt[next];
            dfs2(neighbor, cnt, sum, cur, next);
        }
        return;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // using DFS
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/sum-of-distances-in-tree/solutions/130583/c-java-python-pre-order-and-post-order-dfs-o-n/?envType=daily-question&envId=2024-04-28
        vector<vector<int>> neighbor(n);
        vector<int> cnt(n, 1), sum(n, 0);
        for(vector<int>& edge: edges){
            neighbor[edge[0]].push_back(edge[1]);
            neighbor[edge[1]].push_back(edge[0]);
        }
        dfs1(neighbor, cnt, sum, -1, 0);
        dfs2(neighbor, cnt, sum, -1, 0);
        return sum;
    }
};