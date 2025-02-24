class Solution {
public:
    pair<bool, int> dfs1(vector<vector<int>>& neighbors, int prev, int cur, int bob, vector<int>& amount, int h){
        if(cur == bob){
            amount[cur] = 0;
            return {true, h};
        }
        for(int next: neighbors[cur]){
            if(next == prev)
                continue;
            pair<bool, int> res = dfs1(neighbors, cur, next, bob, amount, h + 1);
            if(res.first){
                if(res.second % 2 == 0 && h == res.second / 2)
                    amount[cur] /= 2;
                else if(h > res.second / 2)
                    amount[cur] = 0;
                return res;
            }
        }
        return {false, -1};
    }
    int dfs2(vector<vector<int>>& neighbors, int prev, int cur, vector<int>& amount){
        int max_val = INT_MIN;
        for(int next: neighbors[cur]){
            if(next == prev)
                continue;
            max_val = max(max_val, amount[cur] + dfs2(neighbors, cur, next, amount));
        }
        return max_val == INT_MIN ? amount[cur] : max_val;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> neighbors(n);
        for(vector<int>& edge: edges){
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        dfs1(neighbors, -1, 0, bob, amount, 0);
        return dfs2(neighbors, -1, 0, amount);
    }
};