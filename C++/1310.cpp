class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // using prefix sum
        // time complexity: O(N + M), where N == arr.size() and M == queries.size()
        vector<int> ans(queries.size());
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] ^ arr[i - 1];
        }
        for(int i = 0; i < queries.size(); i++){
            ans[i] = prefix[queries[i][1] + 1] ^ prefix[queries[i][0]];
        }
        return ans;
    }
};