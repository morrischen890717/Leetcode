class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // using BFS
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/minimum-height-trees/solutions/76055/share-some-thoughts/?envType=daily-question&envId=2024-04-23
        if(n == 1)
            return {0};
        vector<int> ans;
        vector<unordered_set<int>> graph(n);
        for(vector<int>& edge: edges){
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        vector<int> leaves;
        for(int i = 0; i < n; i++){
            if(graph[i].size() == 1)
                leaves.push_back(i);
        }
        while(n > 2){
            n -= leaves.size();
            vector<int> newLeaves;
            for(int leaf: leaves){
                int neighbor = *graph[leaf].begin();
                graph[neighbor].erase(leaf);
                if(graph[neighbor].size() == 1)
                    newLeaves.push_back(neighbor);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};