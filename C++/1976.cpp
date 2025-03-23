class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);
        for(vector<int>& road: roads){
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> d(n, LLONG_MAX), cnt(n, 0);
        pq.push({0, 0});
        d[0] = 0;
        cnt[0] = 1;
        while(!pq.empty()){
            long long cur_d = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if(cur_d > d[cur] || cur_d > d[n - 1])
                continue;
            for(pair<int, int> p: graph[cur]){
                int next = p.first;
                long long new_d = cur_d + p.second;
                if(new_d > d[next])
                    continue;
                if(new_d < d[next]){
                    d[next] = new_d;
                    cnt[next] = cnt[cur];
                    pq.push({new_d, next});
                }
                else if(new_d == d[next]){
                    cnt[next] += cnt[cur];
                    cnt[next] %= MOD;
                }
            }
        }
        return cnt[n - 1];
    }
};