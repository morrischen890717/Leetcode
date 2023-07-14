class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp; // {val, seq_len}
        int n = arr.size();
        int ans = 0;
        for(int i = n - 1; i >= 0; i--){
            int val = arr[i];
            dp[val] = dp.count(val + difference) > 0 ? dp[val + difference] + 1 : 1;
            ans = max(ans, dp[val]);
        }
        return ans;
    }
};