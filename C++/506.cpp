class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> v;
        vector<string> ans(n);
        for(int i = 0; i < n; i++){
            v.push_back({score[i], i});
        }
        sort(v.rbegin(), v.rend());
        for(int i = 0; i < n; i++){
            if(i == 0)
                ans[v[i].second] = "Gold Medal";
            else if(i == 1)
                ans[v[i].second] = "Silver Medal";
            else if(i == 2)
                ans[v[i].second] = "Bronze Medal";
            else
                ans[v[i].second] = to_string(i + 1);
        }
        return ans;
    }
};