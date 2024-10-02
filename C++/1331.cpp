class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end());
        int rank = 0, prev = INT_MAX;
        for(int i = 0; i < n; i++){
            arr[v[i].second] = v[i].first == prev ? rank : ++rank;
            prev = v[i].first;
        }
        return arr;
    }
};