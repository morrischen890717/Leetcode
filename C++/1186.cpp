class Solution {
public:
    int maximumSum(vector<int>& arr) {
        // using bottom-up DP
        // time complexity: O(N), space complexity: O(1)
        int ans = arr[0];
        int n = arr.size();
        pair<int, int> prev = {arr[0], 0}; // {0-deletion, 1-deletion}
        for(int i = 1; i < n; i++){
            pair<int, int> cur;
            cur.first = arr[i] + max(0, prev.first);
            cur.second = max(prev.first, prev.second + arr[i]);
            ans = max({ans, cur.first, cur.second});
            prev = cur;
        }
        return ans;
    }
};