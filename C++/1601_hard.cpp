class Solution {
public:
    void solve(int n, vector<vector<int>>& requests, vector<int>& cnt, int cur, int num, int& ans){
        bool canTransfer = true;
        for(int i = 0; i < n; i++){
            if(cnt[i] != 0){
                canTransfer = false;
                break;
            }
        }
        if(canTransfer)
            ans = max(ans, num);
        if(cur >= requests.size())
            return;
        solve(n, requests, cnt, cur + 1, num, ans); // not choose requests[cur]
        cnt[requests[cur][0]]++;
        cnt[requests[cur][1]]--;
        solve(n, requests, cnt, cur + 1, num + 1, ans); // choose requests[cur]
        cnt[requests[cur][0]]--;
        cnt[requests[cur][1]]++;
        return;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        // this is knapsack 0/1 problem
        int ans = 0;
        vector<int> cnt(n, 0);
        solve(n, requests, cnt, 0, 0, ans);
        return ans;
    }
};