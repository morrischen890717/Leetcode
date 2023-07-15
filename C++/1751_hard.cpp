class Solution {
public:
    int dfs(vector<vector<int>>& events, vector<vector<int>>& dp, int n, int cur, int k){
        if(cur >= n || k < 0)
            return 0;
        if(dp[cur][k] != -1)
            return dp[cur][k];
        int l = cur + 1, r = n - 1;
        while(l <= r){ // binary search, find the next index if we take current event
            int mid = l + (r - l) / 2;
            if(events[mid][0] > events[cur][1]) 
                r = mid - 1;
            else
                l = mid + 1;
        }
        dp[cur][k] = max(dfs(events, dp, n, cur + 1, k), dfs(events, dp, n, l, k - 1) + events[cur][2]); // Knapsack 0/1: not take / take
        return dp[cur][k];
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n, vector<int> (k, -1));
        sort(events.begin(), events.end());
        return dfs(events, dp, n, 0, k - 1);
    }
};