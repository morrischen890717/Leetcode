class Solution {
public:
    int longestIdealString(string s, int k) {
        // using bottom-up DP
        // time complexity: O(k * N) == O(N) (since 0 <= k <= 25), space complexity: O(1)
        int len = s.length();
        vector<int> dp(26, 0);
        for(char c: s){
            int tmp = 0;
            for(int i = max(0, c - 'a' - k); i < min(26, c - 'a' + k + 1); i++){
                tmp = max(tmp, dp[i] + 1);
            }
            dp[c - 'a'] = tmp;
        }
        int ans = 0;
        for(int num: dp){
            ans = max(ans, num);
        }
        return ans;
    }
};