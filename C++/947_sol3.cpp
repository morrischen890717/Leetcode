class Solution {
public:
    int dfs(vector<vector<int>>& stones, vector<bool>& visited, int i){
        visited[i] = true;
        int ans = 1;
        for(int j = 0; j < stones.size(); j++){
            if(!visited[j] && (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]))
                ans += dfs(stones, visited, j);
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        // using DFS
        int ans = 0;
        int n = stones.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i])
                ans += dfs(stones, visited, i) - 1;
        }
        return ans;
    }
};