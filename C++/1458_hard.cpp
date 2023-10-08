class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // using bottom-up DP
        // time complexity: O(N1 * N2), space complexity: O(N1 * N2), where N1 == nums1.size and N2 == nums2.size()
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, -1e7));
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                dp[i][j] = max({nums1[i - 1] * nums2[j - 1], dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1]});
            }
        }
        return dp[n1][n2];
    }
};