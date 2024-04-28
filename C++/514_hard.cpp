class Solution {
public:
    int findRotateSteps(string ring, string key) {
        // using bottom-up DP
        // time complexity: O(N * M^2), space complexity: O(N * M), where N == ring.length() and M == key.length()
        // reference: https://leetcode.com/problems/freedom-trail/solutions/98902/concise-java-dp-solution/?envType=daily-question&envId=2024-04-27
        int n = ring.length(), len = key.length();
        vector<vector<int>> dp(len + 1, vector<int> (n, 0));
        for(int i = len - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                dp[i][j] = INT_MAX;
                for(int k = 0; k < n; k++){
                    if(key[i] == ring[k]){
                        int d = abs(j - k);
                        int step = min(d, n - d);
                        dp[i][j] = min(dp[i][j], step + dp[i + 1][k]);
                    }
                }
            }
        }
        return dp[0][0] + len;
        
    }
};