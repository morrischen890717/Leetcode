class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // using bottom-up DP
        // time complexity: O(N * K), space complexity: O(N)
        int n = arr.size();
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++){
            int max_num = 0;
            for(int j = i; j > i - k && j >= 0; j--){
                max_num = max(max_num, arr[j]);
                dp[i] = max(dp[i], (i - j + 1) * max_num + (j == 0 ? 0 : dp[j - 1]));
            }
        }
        return dp[n - 1];
    }
};