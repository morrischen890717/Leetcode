class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<int> cnt(n, 0);
        for(vector<int>& road: roads){
            cnt[road[0]]++;
            cnt[road[1]]++;
        }
        sort(cnt.begin(), cnt.end());
        for(int i = 0; i < n; i++){
            ans += (long long)(i + 1) * cnt[i];
        }
        return ans;
    }
};