class Solution {
public:
    int dfs(vector<int> &locations, int n, vector<vector<int>> &dp, int start, int finish, int fuel){
        if(dp[start][fuel] != -1)
            return dp[start][fuel];
        long long cnt = (start == finish ? 1 : 0); // 1 stands for do not move anymore
        for(int i = 0; i < n; i++){
            if(i == start)
                continue;
            int cost = abs(locations[i] - locations[start]);
            if(cost <= fuel){
                cnt += dfs(locations, n, dp, i, finish, fuel - cost);
                cnt %= (int)(1e9 + 7);
            }
        }
        return dp[start][fuel] = cnt;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int> (fuel + 1, -1));
        return dfs(locations, n, dp, start, finish, fuel);
    }
};