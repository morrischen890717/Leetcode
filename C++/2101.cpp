class Solution {
public:
    void dfs(vector<vector<int>>& affect, int i, vector<bool>& visited, int& cnt){
        for(int affected: affect[i]){
            if(!visited[affected]){
                visited[affected] = true;
                cnt++;
                dfs(affect, affected, visited, cnt);
            }
        }
        return;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> affect(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                long long x = bombs[i][0] - bombs[j][0], y = bombs[i][1] - bombs[j][1];
                long long d = (long long)x * x + (long long)y * y;
                long long r_i = (long long)bombs[i][2] * bombs[i][2], r_j = (long long)bombs[j][2] * bombs[j][2];
                if(d <= r_i)
                    affect[i].push_back(j);
                if(d <= r_j)
                    affect[j].push_back(i);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int cnt = 1;
            vector<bool> visited(n, false);
            visited[i] = true;
            dfs(affect, i, visited, cnt);
            ans = max(ans, cnt);
        }
        return ans;
    }
};