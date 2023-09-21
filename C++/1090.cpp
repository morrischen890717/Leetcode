class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        // using sort() and unordered_map
        // time complexity: O(NlogN), space complexity: O(N)
        int ans = 0;
        int n = values.size();
        unordered_map<int, int> cnt;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++){
            v[i] = {values[i], labels[i]};
        }
        sort(v.begin(), v.end());
        for(int i = n - 1; i >= 0 && numWanted > 0; i--){
            if(cnt[v[i].second] < useLimit){
                ans += v[i].first;
                cnt[v[i].second]++;
                numWanted--;
            }
        }
        return ans;
    }
};