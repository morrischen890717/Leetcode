class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        /*
        using bottom-up DP
        time complexity: O(N * M), space complexity: O(M), where N = nums1.size() and M = nums2.size()
        */
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(2, vector<int> (n2 + 1, 0));
        int ans = 0;
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                dp[i % 2][j] = nums1[i - 1] == nums2[j - 1] ? dp[(i - 1) % 2][j - 1] + 1: 0;
                ans = max(ans, dp[i % 2][j]);
            }
        }
        return ans;
    }
};