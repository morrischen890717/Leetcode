class Solution {
public:
    bool dfs(vector<vector<int>>& inConnected, vector<bool>& visited, int i){
        if(visited[i])
            return false;
        visited[i] = true;
        for(int j = 0; j < inConnected[i].size(); j++){
            if(inConnected[i][j])
                dfs(inConnected, visited, j);
        }
        return true;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(dfs(isConnected, visited, i))
                cnt++;
        }
        return cnt;
    }
};