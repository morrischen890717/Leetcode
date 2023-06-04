class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0;
        int num = queries.size();
        vector<vector<bool>> visited(2, vector<bool> (n, false));
        vector<int> cnt(2, 0);
        int cnt_r = 0, cnt_c = 0;
        for(int i = num - 1; i >= 0; i--){
            int type = queries[i][0], index = queries[i][1], val = queries[i][2];
            if(visited[type][index])
                continue;
            visited[type][index] = true;
            ans += (n - cnt[type ^ 1]) * val;
            cnt[type]++;
        }
        return ans;
    }
};