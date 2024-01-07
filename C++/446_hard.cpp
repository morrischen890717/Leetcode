class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // using DP
        // time complexity: O(N^2), space complexity: O(N^2)
        // reference: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/solutions/1455658/c-java-python-dp-with-picture-explained-clean-concise/?envType=daily-question&envId=2024-01-07
        int ans = 0;
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                long long diff = (long long)nums[i] - nums[j];
                int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                ans += cnt;
                dp[i][diff] += cnt + 1;
            }
        }
        return ans;
    }
};