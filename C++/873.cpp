class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        /*
        using bottom-up DP
        time complexity: O(N^2), space complexity: O(N^2)
        reference: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/solutions/152343/c-java-python-check-pair/
        */
        int n = arr.size();
        int ans = 0;
        unordered_map<int, int> pos;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++){
            pos[arr[i]] = i;
            for(int j = 0; j < i; j++){
                int k = pos.count(arr[i] - arr[j]) ? pos[arr[i] - arr[j]] : -1;
                dp[j][i] = k >= 0 && k < j ? dp[k][j] + 1 : 2;
                ans = max(ans, dp[j][i]);
            }
        }
        return ans >= 3 ? ans : 0;
    }
};